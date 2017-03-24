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
    | '-' expr # unaryMinus
    | '(' expr ')' # parens
    ;


POW : '^';
MUL : '*';
DIV : '/';
ADD : '+';
SUB : '-';

INT: [1-9][0-9]*;
NEWLINE: '\r'? '\n';
WS: [\r\n\f\t\u000B]+ -> skip;
