#ifndef __DEC_HPP__
#define __DEC_HPP__

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <cassert>


using namespace std;
const int g_size = 4096;


#define PATHNAME "."
#define PROJ_ID 0x1234

key_t getKey()
{
    key_t k = ftok(PATHNAME, PROJ_ID);
    if (k == -1) 
    {
        cerr << "error: " << errno << " : " << strerror(errno) << endl;
        exit(1);
    }
    return k;
}

string toHex(int x)
{
    char buffer[64];
    snprintf(buffer, sizeof buffer, "0x%x", x);
    return buffer;
}

int createShmMth(key_t k, int size, int flag)
{
    int shmid = shmget(k, size, flag);
    if(shmid == -1)
    {
        cerr << "error: " << errno << " : " << strerror(errno) << endl;
        exit(2);
    }
    return shmid;
}

int createShm(key_t k, int size)
{
    umask(0);
    return createShmMth(k, size, IPC_CREAT | IPC_EXCL | 0666);
}

int getShm(key_t k, int size)
{
    return createShmMth(k, size, IPC_CREAT);
}

char* attachShm(int id)
{
    char* start = (char*)shmat(id, nullptr, 0);
    return start;
}

void detachShm(char* start)
{
    int n = shmdt(start);
    assert(n != -1);
    (void)n;
}

void deleteShm(int id)
{
    int n = shmctl(id, IPC_RMID, nullptr);
    assert(n != -1);
    (void)n;
}

#define SERVER 0
#define CLIENT 1

class shmInit
{
public:
    shmInit(int type)
        :_type(type)
    {
        key_t k = getKey();
        if (_type == SERVER) 
        {
            _id = createShm(k, g_size);
        }
        else
        {
            _id = getShm(k, g_size);
        }
        _start = attachShm(_id);
    }
    char* retStart()
    {
        return _start;
    }

    ~shmInit()
    {
        detachShm(_start);
        if (_type == SERVER)
        {
            deleteShm(_id);
        }
    }

private:
    char* _start;
    int _type;
    int _id;
};


#endif