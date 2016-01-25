package melihovv.calculator;

/**
 * Evaluation visitor class.
 */
public class EvalVisitor extends CalculatorBaseVisitor<Integer> {
    @Override
    public Integer visitPrintExpr(CalculatorParser.PrintExprContext ctx) {
        final int value = visit(ctx.expr());
        System.out.println(value);
        return 0;
    }

    @Override
    public Integer visitParens(CalculatorParser.ParensContext ctx) {
        return visit(ctx.expr());
    }

    @Override
    public Integer visitMulDiv(CalculatorParser.MulDivContext ctx) {
        int left = visit(ctx.expr(0));
        int right = visit(ctx.expr(1));
        if (ctx.op.getType() == CalculatorParser.MUL) {
            return left * right;
        }
        return left / right;
    }

    @Override
    public Integer visitAddSub(CalculatorParser.AddSubContext ctx) {
        int left = visit(ctx.expr(0));
        int right = visit(ctx.expr(1));
        if (ctx.op.getType() == CalculatorParser.ADD) {
            return left + right;
        }
        return left - right;
    }

    @Override
    public Integer visitPow(CalculatorParser.PowContext ctx) {
        int left = visit(ctx.expr(0));
        int right = visit(ctx.expr(1));
        return (int) Math.pow(((double) left), ((double) right));
    }

    @Override
    public Integer visitInt(CalculatorParser.IntContext ctx) {
        return Integer.valueOf(ctx.INT().getText());
    }
}
