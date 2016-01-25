grammar Calculator;

prog: stat+;

stat
    : expr NEWLINE # printExpr
    | NEWLINE # blank
    ;

expr
    : <assoc=right> expr '^' expr # pow
    | expr op=('*'|'/') expr # MulDiv
    | expr op=('+'|'-') expr # AddSub
    | INT # int
    | '(' expr ')' # parens
    ;


POW : '^';
MUL : '*';
DIV : '/';
ADD : '+';
SUB : '-';

INT: [1-9][0-9]*;
NEWLINE: '\r'? '\n';
WS: [ \r\v\t]+ -> skip;
