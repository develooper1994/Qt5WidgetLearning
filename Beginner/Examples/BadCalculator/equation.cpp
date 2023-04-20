#include "equation.h"

Equation::Equation(QObject *parent)
    : QObject{parent}
{
    m_action=Action::RESET;
    calculate();
}



void Equation::calculate(){
    double val1 = getValue(m_value1);
    double val2 = getValue(m_value2);
    double sum = 0;

    switch (m_action) {
    case Action::ADD:
        sum = val1 + val2;
        break;
    case Action::SUBTRACT:
        sum = val1 - val2;
        break;
    case Action::MULTIPLY:
        sum = val1 * val2;
        break;
    case Action::DIVIDE:
        sum = val1 / val2;
        break;
    case Action::RESET:
        m_value1.clear();
        m_value2.clear();
        m_sum.clear();
        m_action = Action::NONE;
        break;
    case Action::NONE:
    default:
        // do nothing
        break;
    }

    m_value1 = QString::number(val1);
    m_value2 = QString::number(val2);
    m_sum = QString::number(sum);
    qInfo() << "v1: " << m_value1 << "v2: " << m_value2 << "sum: " << m_sum;
}

QString Equation::toString(){
    QChar op;
    switch (m_action) {
    case Action::ADD:
        op='+';
        break;
    case Action::SUBTRACT:
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
    QString display = QString("%1 %2 %3 = %4").arg(m_value1,op,m_value2,m_sum);
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
