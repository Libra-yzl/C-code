#pragma once

#include <iostream>
#include <string>


class Task
{
public:
    Task()
    {}

    Task(int x, int y, char op) :_x(x), _y(y), _op(op), _result(0), _code(0)
    {}

    void operator()()
    {
        switch (_op)
        {
            case '+':
                _result = _x + _y;
                break;
            case '-':
                _result = _x - _y;
                break;
            case '*':
                _result = _x * _y;
                break;
            case '/':
                // 出现0的情况需要处理
                if (_y == 0)
                    _code = -1; // 表示除法异常
                else
                    _result = _x / _y;

                break;
            case '^':
                _result = _x ^ _y;
                break;
            case '%':
                if (_y == 0)
                    _code = -2; // 表示取模异常
                else
                    _result = _x % _y;
                break;
            default:
                break;
        }
    }

    std::string Arg()
    {
        return std::to_string(_x) + _op + std::to_string(_y) + "="; 
    }

    std::string Ret()
    {
        return std::to_string(_result) + '(' + std::to_string(_code) + ')';
    }

    ~Task()
    {}

private:
    int _x; // 操作数
    int _y; // 操作数
    char _op; // 运算操作
    int _result; // 运算结果
    int _code; // 异常码 正常为0
};



// #pragma once
// #include <iostream>
// #include <string>

// class Task
// {
// public:
//     Task()
//     {
//     }
//     Task(int x, int y, char op) : _x(x), _y(y), _op(op), _result(0), _exitCode(0)
//     {
//     }
//     void operator()()
//     {
//         switch (_op)
//         {
//         case '+':
//             _result = _x + _y;
//             break;
//         case '-':
//             _result = _x - _y;
//             break;
//         case '*':
//             _result = _x * _y;
//             break;
//         case '/':
//         {
//             if (_y == 0)
//                 _exitCode = -1;
//             else
//                 _result = _x / _y;
//         }
//         break;
//         case '%':
//         {
//             if (_y == 0)
//                 _exitCode = -2;
//             else
//                 _result = _x % _y;
//         }
//         break;
//         default:
//             break;
//         }
//     }
//     std::string formatArg()
//     {
//         return std::to_string(_x) + _op + std::to_string(_y) + "=";
//     }
//     std::string formatRes()
//     {
//         return std::to_string(_result) + "(" + std::to_string(_exitCode) + ")";
//     }
//     ~Task()
//     {
//     }

// private:
//     int _x;
//     int _y;
//     char _op;

//     int _result;
//     int _exitCode;
// };