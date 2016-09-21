//**************************************************************
// EX_VARARG_01  :  可変個引数処理  [穴開きProgram]
//                  与えられた引数の数だけ処理する
//                                                 2016, Sumida
//**************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>                               // 可変個引数を使用する時指定

void dynamic_argument(int, ...);

struct KOZOTAI {
  int  num;
  int  a;
};

int main() {
  int  count=1;                                   // 引数Counter
  int  param1=0;
  int  param2=0;
  char param3=' ';
  char param4[20];
  struct KOZOTAI param5;

  printf("今からPrint処理の為の引数を複数入力します\n引数が不要になった時点で 0を入力して下さい\n\n");
  while(1) {
    printf("param1(int)を入力 (入力終了の場合0)>");
    rewind(stdin);
    scanf("%d",&param1);
    if (param1 == 0) { break;}
    count++;

    printf("param2(int)を入力 (入力終了の場合0)>");
    rewind(stdin);
    scanf("%d",&param2);
    if (param2 == 0) { break;}
    count++;

    printf("param3(char)を入力 (入力終了の場合0)>");
    rewind(stdin);
    scanf("%c",&param3);
    if (param3 == '0') { break;}
    count++;

    printf("param4(文字列)を入力 (入力終了の場合0)>");
    rewind(stdin);
    scanf("%s",&param4[0]);
    if ( param4[0]=='0' ) { break;}
    count++;

    printf("param5(構造体)Member変数(int)を入力 (入力終了の場合0)>");
    rewind(stdin);
    scanf("%d",&param5);
    if (param5.num == 0) { break;}
    count++;
    break;
  }
  dynamic_argument(count, param1, param2, param3, &param4[0], &param5); // Print処理
  return 0;
}

void dynamic_argument(int count, ...) {           // Print処理(可変個引数)
  struct KOZOTAI *param5;

  printf("\n可変個引数処理で入力内容をPrintします\n\n");
  if (count >= 1){
     va_list args;                                // 引数Listを作成
     va_start(args, count);                  // 引数countの次の引数からva_argで順次取り込む
                                                  // (以下は"三項演算子" を使った処理...使い方を覚えて下さい)
                                                  //   ((条件文)?  true(>0)の場合の処理 : false(0)の場合の処理);
     ((--count)? printf("param1=%d\n",va_arg(args, int))        : count=1);  // int処理
     ((--count)? printf("param2=%d\n",va_arg(args, int))        : count=1);  // int処理
     ((--count)? printf("param3=%c\n",(char)va_arg(args, char)) : count=1);  // char処理(char型はintで取り込まれるのでcharでCast)
     ((--count)? printf("param4=%s\n",va_arg(args, char*)) : count=1);  // 文字列処理
     if (--count) {
        param5 = va_arg(args,struct KOZOTAI*);                                   // 構造体処理
        printf("param5=%d\n",param5->num);
     }
     va_end(args);
  }
}
