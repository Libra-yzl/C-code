#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define NAME "yzl"

int main()
{
    const char* user = getenv("USER");
    if (user == NULL) perror("getenv");
    else if (strcmp(user, NAME) == 0)
    {
        printf("你可以进行操作\n");
    }
    else{
        printf("对不起 %s用户 很抱歉 您无权进行此操作\n", user);
    }
    return 0;
}

//int main()
//{
//    printf("you can see me\n");
//    return 0;
//}

/*

//void Usage(const char* name)
//{
//    printf("\n Usage:%s -[a|b|c]\n\n", name);
//    exit(0);
//}
//
//int main(int argc, char* argv[])
//{
//    //命令行参数
//    if (argc != 2) Usage(argv[0]);
//    else if (strcmp(argv[1], "-a") == 0) printf("正确的\n");
//    else if (strcmp(argv[1], "-b") == 0) printf("中肯的\n");
//    else if (strcmp(argv[1], "-c") == 0) printf("是我的\n");
//    else printf("不可以涩涩喔\n");
//    return 0;
//}
//
//int main()
//{
//    extern char** environ;
//    for (int i = 0; environ[i]; ++i)
//    {
//        printf("environ[%d]:%s\n", i, environ[i]);
//    }
//    return 0;
//}
//
//int main(int argc, char* argv[], char* envp[])
//{
//    extern char** environ;
//    for (int i = 0; envp[i]; ++i)
//    {
//        printf("envp[%d]:%s\n", i, envp[i]);
//    }
//    return 0;
//}
   37  clear
   38  ll
   39  cd myCode/
   40  ll
   41  clear
   42  ll
   43  vim test.c 
   44  cd ..
   45  vim .vimrc 
   46  cd myCode/
   47  vim test.c 
   48  cd ..
   49  vim .vimrc 
   50  cd myCode/
   51  vim test.c 
   52  gcc test.c -o test.ext
   53  ll
   54  mv test.ext test.exe
   55  ll
   56  clear
   57  ll
   58  ./test.ext
   59  rm -f test.exe
   60  ll
   61  ./a.out 
   62  gcc test.c -o test.exe
   63  ll
   64  ./test.exe
   65  ./a.out ./test.exe
   66  ./test.exe
   67  rm -f ./*a
   68  ll
   69  rm -f ./a
   70  ll
   71  rm -f ./*.out
   72  ll
   73  ./test.exe 
   74  cp test.c ../
   75  ll
   76  clear
   77  cd ..
   78  ll
   79  cat test.c
   80  rm -f test.c
   81  ll
   82  cat install.sh
   83  rm install.sh 
   84  ll
   85  clear
   86  ls -al
   87  vim .vimrc
   88  top 10
   89  top
   90  sudo
   91  cd ./
   92  cd myCode/
   93  ll
   94  clear
   95  vim test.
   96  ll
   97  ls -al
   98  vim test.c
   99  vim ../.vimrc 
  100  vim test.c
  101  vim ../.vimrc 
  102  vim test.c
  103  ./test.exe 
  104  cd ..
  105  ll
  106  cd /
  107  ll
  108  cd /home
  109  ll
  110  cdyzl
  111  cd yzl
  112  cd zhw
  113  ll
  114  ls
  115  cd ..
  116  su
  117  cd zhw
  118  su
  119  ll
  120  cd zhw/
  121  su
  122  pwd
  123  ll
  124  cd /
  125  ll
  126  cd pwd
  127  cd -
  128  ll
  129  clear
  130  mkdir myFile
  131  ll
  132  mkdir myCode
  133  lll
  134  l
  135  ll
  136  cd myCode/
  137  touch test.txt
  138  ll
  139  cl
  140  clear 
  141  nano test.txt 
  142  ll
  143  mv test.txt test.c
  144  ll
  145  cat test.c
  146  gcc test.c
  147  ll
  148  ./a.out 
  149  cd /home
  150  l
  151  ll
  152  su
  153  su\
  154  su
  155  ll
  156  cd ..
  157  ll
  158  cd yzl
  159  ll
  160  cd myCode
  161  ll
  162  cat test.c
  163  vim test.c
  164  cd .
  165  cd ..
  166  ls -al
  167  cd myCode/
  168  ll
  169  clear
  170  cim test.c
  171  vim test.c
  172  ll
  173  gcc -E test.c -o test.i
  174  ll
  175  vim test.i
  176  gcc -S test.i
  177  ll
  178  vim test.s
  179  gcc -c test.s
  180  ll
  181  vim test.o
  182  clear
  183  ll
  184  rm test.i
  185  rm test.o
  186  rm test.s
  187  rm test.exe
  188  ll
  189  gcc test.c -o test
  190  ll
  191  file test.c
  192  file test
  193  ldd test
  194  ldd test.c
  195  clear
  196  ll
  197  gcc test.c -o test_static -static
  198  yum install -y libc-static
  199  su
  200  ll
  201  claer
  202  clear
  203  ll
  204  gcc test.c -o test_static -static
  205  ll
  206  ldd test_static 
  207  file test_static 
  208  su
  209  clear
  210  ll
  211  rm test
  212  rm test_static 
  213  touch Makefile
  214  vim Makefile
  215  make
  216  ll
  217  rm test
  218  ll
  219  ls -a;
  220  ls -al
  221  ll
  222  clear
  223  ll
  224  mkae
  225  clear
  226  ll
  227  make
  228  ll
  229  ./test
  230  sudo ls
  231  clear
  232  ls /etc/sudoers
  233  su
  234  sudo ll
  235  sudo ls
  236  chown root myFile
  237  ll
  238  cd ..
  239  ll
  240  cd ..
  241  ll
  242  cd zyl
  243  cd yzl
  244  ll
  245  clear
  246  ll
  247  chown root myFile
  248  sudo chown root myFile
  249  ll
  250  chmod 000 myFile
  251  sudo chmod 007 myFile
  252  ll
  253  cd myFile
  254  rm -rf myFile
  255  ll
  256  cd myCode/
  257  ll
  258  clear
  259  ll
  260  vim Makefile 
  261  make
  262  ll
  263  ./test
  264  make clean
  265  ll
  266  make
  267  make clean
  268  ll
  269  clear
  270  vim test.c
  271  vim Makefile 
  272  cat Makefile 
  273  pwd
  274  ll
  275  clear
  276  cd myCode/
  277  ll
  278  vim Makefile 
  279  cat Makefile 
  280  mkdir proc
  281  ll
  282  cd proc/
  283  ll
  284  clear
  285  touch proc.h
  286  touch proc.c
  287  touch main.c
  288  ll
  289  vim proc.h
  290  ll
  291  vim Makefile
  292  cat Makefile
  293  ll
  294  clear
  295  ll
  296  make
  297  l
  298  ll
  299  ./process 
  300  clear
  301  ll
  302  vim proc.c
  303  make clean
  304  ll
  305  make
  306  ./process 
  307  clear
  308  vim proc.c
  309  make clean
  310  make
  311  ./process 
  312  vim proc.c
  313  make clean
  314  make
  315  vim proc.c
  316  make
  317  ./process 
  318  vim proc.c
  319  make clean
  320  make
  321  ./process 
  322  clear
  323  vim proc.c
  324  make clean
  325  make
  326  ./process 
  327  git vision
  328  git --version
  329  git clone https://github.com/Libra-yzl/C-code.git
  330  ll
  331  ls -al
  332  cd C-code/
  333  ll
  334  cd ..
  335  clear
  336  ll
  337  rm -rf C-code
  338  ll
  339  ls -al
  340  cd ..
  341  ll
  342  rm Makefile 
  343  cat test.c
  344  rm test.c 
  345  ll
  346  clear
  347  git clone https://github.com/Libra-yzl/C-code.git
  348  pwd
  349  ll
  350  git clone https://github.com/Libra-yzl/C-code.git
  351  cd M
  352  cd myCode/
  353  ll
  354  cd proc 
  355  ll
  356  cd ..
  357  ll
  358  git clone https://github.com/Libra-yzl/C-code.git
  359  clear
  360  exit
  361  cd myCode/
  362  ll
  363  cd proc/
  364  ll
  365  clear
  366  vim proc.c
  367  make clean
  368  make
  369  ./process 
  370  vim proc.c
  371  rm ~/.local/share/nvim/swap//%home%yzl%myCode%proc%proc.c.swp
  372  ll
  373  vim proc.c
  374  ./process 
  375  vim proc.c
  376  make clean
  377  make
  378  ./process 
  379  vim proc.c
  380  make clean
  381  make
  382  ./process 
  383  cat proc.c
  384  cd ..
  385  ll
  386  cd C-code/
  387  cp -r ../proc/ .
  388  tree .
  389  ll | grep proc
  390  clear
  391  ll
  392  cd proc/
  393  ll
  394  cd ..
  395  git commit -m "给进度条增加背景颜色 可以以色块形式展示进度条"
  396  git add .
  397  git commit -m "给进度条增加背景颜色 可以以色块形式展示进度条"
  398  git push
  399  git log
  400  cd ..
  401  ll
  402  mv proc proc-committed
  403  ll
  404  cd proc-committed/
  405  ll
  406  cd ..
  407  l
  408  ll
  409  cd ..
  410  ll
  411  cd myCode/
  412  ll
  413  git clone https://github.com/Libra-yzl/C-code.git
  414  git pull
  415  ls -al
  416  cd C-code/
  417  ll
  418  ls -al
  419  ll | grep .g
  420  list -al | grep .g
  421  ls -al | grep .g
  422  clear
  423  tree .git
  424  clear
  425  cp -r ../proc/ .
  426  ll
  427  git add .
  428  tree .
  429  git commit -m "Linux-进度条实现"
  430  git config --global user.email "1684595753@qq.com"
  431  git config --global user.name "江晚风"
  432  git commit -m "Linux-进度条实现"
  433  git push
  434  git config --global push.default matching
  435  git push
  436  git config --global push.default simple
  437  git push
  438  clear
  439  git push
  440  git config --global push.default simple
  441  git push
  442  git remote set-url origin git@github.com:Libra-yzl/C-code.git
  443  cd ..
  444  ll
  445  ls -al
  446  rm -rf C-code
  447  ll
  448  ls -al
  449  git clone git@github.com:Libra-yzl/C-code.git
  450  ll
  451  git clone git@github.com:Libra-yzl/C-code.git
  452  ll
  453  git remote set-url origin git@github.com:Libra-yzl/C-code.git
  454  git clone git@github.com:Libra-yzl/C-code.git
  455  ssh ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
  456  cd ..
  457  ll
  458  ssh-keygen -t rsa -b 4096 -C "1684595753@qq.com"
  459  ll
  460  ls -al
  461  cd .ssh
  462  ls -al
  463  ll
  464  cat known_hosts 
  465  cat id_rsa.pub 
  466  git clone git@github.com:Libra-yzl/C-code.git
  467  ll
  468  rm -rf C-code/
  469  ll
  470  cd ..
  471  ll
  472  ls -al
  473  cd myCode/
  474  ll
  475  git clone git@github.com:Libra-yzl/C-code.git
  476  ll
  477  clear
  478  cd C-code/
  479  ll
  480  cp -r ../proc/ .
  481  ll | grep proc
  482  git add .
  483  git commit -m "Linux-进度条实现"
  484  git push
  485  cd ../proc/
  486  ll
  487  clear
  488  ll
  489  vim proc.c
  490  ./process 
  491  vim proc.c
  492  make clean
  493  make
  494  ./process 
  495  vim proc.c
  496  make clean
  497  make
  498  vim proc.c
  499  make clean
  500  make
  501  ./process 
  502  cat proc.c
  503  vim proc.c
  504  make clean
  505  make
  506  ./process 
  507  vim proc.c
  508  make clean
  509  make
  510  ./process
  511  vim proc.c
  512  make clean
  513  make
  514  ./process 
  515  vim proc.c
  516  make clean
  517  make
  518  ./process 
  519  vim proc.c
  520  make clean
  521  make
  522  ./process 
  523  make clean
  524  vim proc..c
  525  ll
  526  vim proc.c
  527  make
  528  ./process 
  529  vim proc.c
  530  l
  531  ll
  532  cd myCode/
  533  ll
  534  cd proc-committed/
  535  ll
  536  ./process 
  537  cat proc.c
  538  vim proc.c
  539  cd ..
  540  ll
  541  clear
  542  ll
  543  cd o
  544  cd proc-committed/
  545  ll
  546  cd ..
  547  mkdir L-6_19
  548  ll
  549  cd L-6_19/\
  550  ll
  551  mkdir gdb
  552  ll
  553  cd gdb/
  554  cp ../../proc-committed/ .
  555  cp -r ../../proc-committed/ .
  556  ll
  557  mv proc-committed/* .
  558  ll
  559  rm -r proc-committed
  560  ;;
  561  ll
  562  clear
  563  vim Makefile 
  564  make clean
  565  make
  566  gdb process 
  567  ll
  568  yun install gdb
  569  yum install gdb
  570  sudo yum install gdb
  571  gdb process 
  572  ll
  573  rm proc*
  574  l
  575  ll
  576  vim main.c 
  577  vim Makefile 
  578  make 
  579  vim main.c 
  580  vim Makefile 
  581  make
  582  ll
  583  ./main
  584  gdb main
  585  claer
  586  clear
  587  pwd
  588  ll
  589  cd ../../
  590  ll
  591  cd C-code/
  592  ll
  593  clear
  594  cp -r ../L-6_19/ .
  595  git add .
  596  git commit -m "gdb调试理解以及简单的使用"
  597  ll
  598  git push
  599  git pull
  600  cd ..
  601  ll
  602  mv L-6_19/ L-6_19-committed
  603  ll
  604  cd L-6_19-committed/
  605  ll
  606  cd ..
  607  ll
  608  cd "myCode"
  609  cd "myCode/L-6_20"
  610  ps axj | grep process 
  611  ps axj head 1
  612  ps --help
  613  ps --headers
  614  ps -head
  615  ps --head
  616  ps -headers
  617  ps --headers
  618  ps --headers && ps axj | grep process
  619  ps -p process
  620  ps -p process --headers
  621  ps axj | head -1
  622  ps axj | head -1 && ps axj | grep process
  623  kill -9 2248
  624  ps axj | head -1 && ps axj | grep process
  625  cd /proc/
  626  ll
  627  ls
  628  cd myCode/
  629  ll
  630  mkdir +
  631  ll
  632  rm -rf +
  633  ;ll
  634  ll
  635  mkdir L-6_20
  636  cd L-6_20
  637  touch process
  638  touch Makefile
  639  mv process process.c
  640  ll
  641  vim process.c 
  642  vim Makefile 
  643  make
  644  ./process 
  645  vim process.c 
  646  make clean
  647  ll
  648  make
  649  ./process 
  650  make clean
  651  vim process.c 
  652  man fork
  653  man getpid
  654  vim process.c 
  655  mak
  656  make
  657  ,.p
  658  ./process 
  659  vim process.c
  660  make clean
  661  make
  662  ./process 
  663  ./p
  664  ./process 
  665  vim process.c
  666  make clean
  667  make
  668  ./process 
  669  cd ..
  670  ll
  671  cd C-code/
  672  cp -r ../L-6_20/ .
  673  git pull
  674  git add .
  675  git commit -m "简单理解进程以及fork(系统调用接口函数)"
  676  git push
  677  git log
  678  pwd
  679  cd 
  680  ls 
  681  ll
  682  pwd
  683  cd ..
  684  ll
  685  cd zhw/
  686  cd yzl
  687  cd myCode/
  688  ll
  689  cd proc-committed/
  690  ll
  691  vim proc.c
  692  cd ..
  693  ll
  694  cd yzl
  695  ll
  696  cd myCode/
  697  ll
  698  cd L-8_8
  699  mkdir L-8_8
  700  cd L-8_8/
  701  ll
  702  vim test.cpp
  703  vim test.h
  704  ll
  705  ls -l
  706  ll
  707  vim test.h
  708  ll
  709  vim test.h
  710  ll
  711  vim test.h
  712  ll
  713  cat test.cpp 
  714  cat test.h
  715  vim test.cpp 
  716  vim makefile
  717  ll
  718  g++ test.cpp
  719  gcc test.cpp
  720  cat test.cppp
  721  cat test.cpp
  722  vim test.cpp
  723  g++ -o test.cpp
  724  g++
  725  yum install g++
  726  sudo yum install g++
  727  cd ..
  728  ll
  729  cd proc-committed/
  730  ll
  731  cd Makefile 
  732  cat Makefile 
  733  cd ..
  734  cd L-8_8/
  735  ll
  736  gcc -o test.cpp
  737  pwd
  738  ll
  739  cd myCode/
  740  ll
  741  mkdir L-8_10
  742  cd L-8_10
  743  vim test.c
  744  cat test.c
  745  gcc test.c
  746  ll
  747  ./a/
  748  ./a.out 
  749  vim test.c 
  750  ll
  751  cd m
  752  cd myCode/
  753  ll
  754  mkdir L-8_11
  755  cd L-8_11
  756  ll
  757  vim test.c
  758  vim Makefile
  759  make
  760  ll
  761  ./test
  762  make clean
  763  ll
  764  make clean
  765  ll
  766  make
  767  ll
  768  make
  769  touch test.c
  770  make
  771  l
  772  ll
  773  ./test
  774  stat test
  775  ldd test
  776  cd ..
  777  ll
  778  cd C-code/
  779  git pull
  780  git add .
  781  git commit -m "提交代码(Linux)"
  782  cd ..
  783  ll
  784  cd C-code/
  785  git log
  786  cd myCode/
  787  ll
  788  cd C
  789  cd C-code/
  790  git pull
  791  mkdir L-8_13
  792  cd L-8_13
  793  ll
  794  touch proc.c
  795  touch proc.h
  796  touch main.c
  797  vim Makefile
  798  ll
  799  vim main.c 
  800  vim proc.h
  801  vim main.c 
  802  vim proc.c
  803  vim main.c
  804  vim proc.h
  805  vim proc.c
  806  make
  807  ./process 
  808  vim proc.c
  809  make
  810  vim Makefile 
  811  make
  812  man 3 usleep
  813  vim Makefile 
  814  vim proc.c
  815  make
  816  vim proc.c
  817  vim proc.h
  818  make
  819  vim proc.c
  820  vim proc.h
  821  make
  822  ./process 
  823  vim proc.c
  824  make
  825  vim proc.h
  826  make
  827  clean
  828  make clean
  829  make
  830  vim proc.c
  831  make
  832  ./process 
  833  vim proc.c
  834  make
  835  ./process 
  836  vim proc.c
  837  vim proc.h
  838  make
  839  ./process 
  840  vim proc.c
  841  make
  842  ./process 
  843  vim proc.c
  844  make
  845  ./process 
  846  vim proc.c
  847  make
  848  ./process 
  849  vim proc.c
  850  make
  851  ./process 
  852  vim proc.c
  853  vim Makefile 
  854  vim proc.c
  855  make
  856  ./process 
  857  vim proc.c
  858  make
  859  ./process 
  860  vim proc.c
  861  ./process 
  862  vim proc.c
  863  make
  864  ./process 
  865  vim proc.c
  866  make
  867  ./process 
  868  vim test.c
  869  vim test.h
  870  vim test.c
  871  vim Makefile 
  872  make
  873  vim Makefile 
  874  make
  875  ./test
  876  vim test.c
  877  make
  878  make clean
  879  make
  880  ./process 
  881  ./test
  882  vim Makefile 
  883  make
  884  make clean
  885  make
  886  ./test 
  887  gdb test
  888  gdb process
  889  gdb test
  890  ll
  891  mv test test-debug
  892  mv process process-release
  893  ll
  894  ./process-release 
  895  cd ..
  896  git add
  897  git add .
  898  git commit -m "Linux_gdb"
  899  git push
  900  cd ..
  901  ll
  902  ls -al
  903  cd C-code/
  904  ls -al
  905  cd ..
  906  ll
  907  git log
  908  cd C-code/
  909  git lod
  910  git log
  911  cd "myCode/L-8_14"
  912  ./myprocess 
  913  cd myCode/
  914  ll
  915  cd L-8_14
  916  mkdir L-8_14
  917  cd L-8_14
  918  ll
  919  touch test.c
  920  vim test.c 
  921  vim makefile
  922  make
  923  ./myprocess 
  924  vim test.c
  925  make
  926  ./myprocess 
  927  ps axj | head -1
  928  ps axj | head -1 && ps axj | grep myprocess | grep -v grep
  929  cd "myCode/L-8_16"
  930  cd "myCode/L-8_16"
  931  ./test 
  932  cd "myCode/L-8_16"
  933  ./test 
  934  cd myCode/
  935  ll
  936  mkdir L-8_16
  937  cd L-8_16
  938  ll
  939  vim test.c
  940  man fork
  941  man getpid
  942  vim test.c
  943  vim makefile
  944  make
  945  ./test 
  946  vim test.c
  947  make
  948  ./test 
  949  ps axj | head -1 && ps axj | grep test | grep -v grep
  950  ps axj | head -1 && ps axj | grep test | grep 8587 | grep -v grep
  951  ls -dl /proc/8587
  952  ll -d /proc/8587
  953  ll -ad /proc/8587
  954  pwd
  955  -pwd
  956  ps axj | head -1 && ps axj | grep 8587
  957  ll
  958  cd myCode/
  959  ll
  960  cd L-8_17
  961  ll
  962  ./test
  963  test -d
  964  make
  965  test -d
  966  test -a
  967  ./test -a
  968  ./test -d
  969  cd ..
  970  ;;
  971  cd L-8_17
  972  ll
  973  vim test.c
  974  echo PATH
  975  echo $PATH
  976  export PATH=$PATH:/home/yzl/myCode/L-8_17
  977  ./test
  978  ./test -a
  979  test -a
  980  echo $PATH
  981  test
  982  make
  983  test
  984  ./test
  985  vim test.c
  986  make
  987  ./test 
  988  test
  989  sudo export PATH=$PATH:/home/yzl/myCode/L-8_17
  990  pwd
  991  export PATH=$PATH:/home/yzl/myCode/L-8_17
  992  test
  993  ll
  994  test
  995  export PATH=$PATH:/home/yzl/myCode/L-8_17/test
  996  test
  997  ./test
  998  test
  999  echo $PATH
 1000  which test
 1001  cd myCode/
 1002  cd L-8_17
 1003  ll
 1004  which ls
 1005  vim test.c
 1006  echo $PATH
 1007  mv test.c proc.c
 1008  ll
 1009  vim makefile 
 1010  make
 1011  ./proc
 1012  which proc
 1013  export PATH=$PATH:/home/yzl/myCode/L-8_17
 1014  which proc
 1015  ./proc
 1016  proc
 1017  cd .
 1018  cd ..
 1019  proc
 1020  cd L-8_17
 1021  ll
 1022  rm -rf test
 1023  ll
 1024  make clean
 1025  l
 1026  ll
 1027  make
 1028  proc
 1029  echo $USER
 1030  echo $HoSTNAME
 1031  echo $HOSTNAME
 1032  env
 1033  history >> test.c
 1034  ll
 1035  rm -f test.c
 1036  history >> proc.c 
 */
