#include <iostream>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v3\BasicClasses.cpp>

int main(){
    std::cout << math::StandardForm(2,5) << std::endl;
    std::cout << math::StandardForm(2,10) << std::endl;

    std::cout  << "2e5 + 2e10 = "<< math::StandardForm(2,5) + math::StandardForm(2,10) << std::endl;
    std::cout  << "2e10 - 2e5 = "<< math::StandardForm(2,10) - math::StandardForm(2,5) << std::endl;
    std::cout  << "2e10 * 2e5 = "<< math::StandardForm(2,10) * math::StandardForm(2,5) << std::endl;
    std::cout  << "2e10 / 2e5 = "<< math::StandardForm(2,10) / math::StandardForm(2,5) << std::endl;
    std::cout  << "2e10 ^ 2e5 = "<< (math::StandardForm(2,10) ^ math::StandardForm(2,5)) << std::endl;

    std::cout << "---------------------------\n";

    math::Variables::mapType m1;
    m1['x'] = math::StandardForm("20");
    m1['y'] = math::StandardForm("1");
    m1['z'] = math::StandardForm("5");
    m1['a'] = math::StandardForm("3");
    m1['b'] = math::StandardForm("8");

    math::Variables::mapType m2;
    m2['x'] = math::StandardForm("10");
    m2['w'] = math::StandardForm("1");
    m2['z'] = math::StandardForm("10");
    m2['u'] = math::StandardForm("3");
    m2['b'] = math::StandardForm("-5");

    math::Variables v1 = math::Variables(m1);
    math::Variables v2 = math::Variables(m2);
    math::Variables v3 = math::Variables("m^2r^5u^1o^(2e4)k^12");
    math::Variables v4 = math::Variables("a^2b^3c^4");
    math::Variables v5 = math::Variables("x^3y^2z^1");
    math::Variables v6 = math::Variables("p^3q^(2c)d^5");
    math::Variables v7 = math::Variables("m^3p^2q^(2c)d^(1e1)");

    std::cout << "v1 * v2  = " << v1 * v1 << std::endl;
    std::cout << "v1 / v2  = " << v1 / v2 << std::endl;
    std::cout << "v3 = " << v3 << std::endl;
    std::cout << "v4 = " << v4 << std::endl;
    std::cout << "v5 = " << v5 << std::endl;
    std::cout << "v6 = " << v6 << std::endl;
    std::cout << "v7 = " << v7 << std::endl;
    std::cout << "v3 variable : m = " << v3['m'].toDouble() << std::endl;
    std::cout << "v3 variable : r = " << v3['r'].toScientificNotation() << std::endl;    
    std::cout << "v3 variable : u = " << v3['u'].toEngineeringNotation() << std::endl;
    std::cout << "v3 variable : o = " << v3['o'] << std::endl;
    std::cout << "v3 variable : k = " << v3['k'] << std::endl;
 
    std::cout << "---------------------------\n";

    math::AlgebraicTerm t1 = math::AlgebraicTerm(math::StandardForm(2,5),math::Operation::NO_OPERATOR);
    math::AlgebraicTerm t2 = math::AlgebraicTerm(math::StandardForm(2,10),math::Operation::ADD);
    std::cout << t1 << t2 << "=" << t1.performOperationBetweenTerms(t2).at(0) << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm(2,5),math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm(2,10),math::Operation::SUBTRACT);
    std::cout << t1  << t2 << "=" << t1.performOperationBetweenTerms(t2).at(0)  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm(2,5),math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm(2,10),math::Operation::MULTIPLY);
    std::cout << t1 <<  t2 << "=" << t1.performOperationBetweenTerms(t2).at(0)  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm(2,5),math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm(2,10),math::Operation::DIVIDE);
    std::cout << t1 << t2 << "=" << t1.performOperationBetweenTerms(t2).at(0) << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm(2,5),math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm(2,10),math::Operation::POWER);
    std::cout << t1 <<  t2 << "=" << t1.performOperationBetweenTerms(t2).at(0) << std::endl;

    std::cout << "---------------------------\n";

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v2,math::Operation::MULTIPLY);
    std::cout << "t1 * t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))<< std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v1,math::Operation::DIVIDE);
    std::cout << "t1 / t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v2,math::Operation::DIVIDE);
    std::cout << "t1 / t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v1,math::Operation::ADD);
    std::cout << "t1 + t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v2,math::Operation::ADD);
    std::cout << "t1 + t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v1,math::Operation::SUBTRACT);
    std::cout << "t1 - t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v2,math::Operation::SUBTRACT);
    std::cout << "t1 - t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))  << std::endl;

    t1 = math::AlgebraicTerm(math::StandardForm("2e5"),v1,math::Operation::NO_OPERATOR);
    t2 = math::AlgebraicTerm(math::StandardForm("4e8"),v2,math::Operation::POWER);
    std::cout << "t1 ^ t2  = " << math::AlgebraicExpression(t1.performOperationBetweenTerms(t2))  << std::endl;

    std::cout << "---------------------------\n";

    std::vector<math::AlgebraicTerm> terms1 = {
        math::AlgebraicTerm(math::StandardForm("2"), math::Operation::ADD),
        math::AlgebraicTerm(math::StandardForm("3"), math::Operation::ADD),
        math::AlgebraicTerm(math::StandardForm("4"), math::Operation::ADD)
    };
    std::vector<math::AlgebraicTerm> terms2 = {
        math::AlgebraicTerm(math::StandardForm("1"), v1, math::Operation::ADD),
        math::AlgebraicTerm(math::StandardForm("2"), v2, math::Operation::SUBTRACT),
        math::AlgebraicTerm(math::StandardForm("3"), v2, math::Operation::ADD)
    };

    math::AlgebraicExpression expr1(terms1);
    math::AlgebraicExpression expr2(terms2);
    std::cout << "expr1 = " << expr1 << std::endl;
    std::cout << "expr2 = " << expr2 << std::endl;

    std::cout << "expr1.calculate() = " << expr1.calculate() << std::endl;
    std::cout << "expr2.calculate() = " << expr2.calculate() << std::endl;

    std::cout << "---------------------------\n";

    t1 = math::AlgebraicTerm(math::StandardForm("4e8"),v2,math::Operation::ADD);
    std::cout << "t1.evaluteTermWithVariableValues(v2) = "<< t1.evaluteTermWithVariableValues(v2) << std::endl;

    std::cout << "expr1.calculateExpressionWithVariableValues(v2) = "<< expr1.calculateExpressionWithVariableValues(v2) << std::endl;

    t1 = math::AlgebraicTerm("+2fh^4");
    t2 = math::AlgebraicTerm("+(5e12)am^4g^4y^(2e10)");
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;
    return 0;
}
