%{
  #include "y.tab.h"
%}
%%
1 {return ONE;}
0 {return ZERO;}
\n {return 0;}
%%
int yywrap(){
    return 1;
}