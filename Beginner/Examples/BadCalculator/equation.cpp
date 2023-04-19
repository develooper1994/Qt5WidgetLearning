#include "equation.h"

Equation::Equation(QObject *parent)
    : QObject{parent}
{
    m_action=Action::RESET;
    calculate();
}



void Equation::calculate(){
    double val1 =
    switch (m_action) {
    case Action::ADD:
        break;
    case Action::SUBSTRACT:
        break;
    case Action::MULTIPLY:
        break;
    case Action::DIVIDE:
        break;
    case Action::RESET:
        break;
    case Action::NONE:
    default:
        // do nothing
        break;
    }
}

QString Equation::toString(){
    QString display;
    display.append(m_value1);
    display.append(" ");
    QChar op;
    switch (m_action) {
    case Action::ADD:
        op='+';
        break;
    case Action::SUBSTRACT:
        op='-';
        break;
    case Action::MULTIPLY:
        op='*';
        break;
    case Action::DIVIDE:
        op='/';
        break;
    case Action::NONE:
    case Action::RESET:
    default:
        op='?';
        break;
    }
    display.append(" ");
    display.append(m_value2);
    display.append(" = ");
    display.append(m_sum);
    return display;
}

double Equation::getValue(QStringView data){
    bool ok;
    double value = data.toDouble(&ok);
    if(!ok) value = 0;
    return value;
}



// getter-setter
QString Equation::sum() const{
    return m_sum;
}

void Equation::setSum(const QString &newSum){
    m_sum = newSum;
}

QString Equation::value1() const{
    return m_value1;
}

void Equation::setValue1(const QString &newValue1){
    m_value1 = newValue1;
}

QString Equation::value2() const{
    return m_value2;
}

void Equation::setValue2(const QString &newValue2){
    m_value2 = newValue2;
}

Equation::Action Equation::action() const{
    return m_action;
}

void Equation::setAction(Equation::Action newAction){
    m_action = newAction;
}
