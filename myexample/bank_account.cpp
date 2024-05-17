#include <iostream>
#include <string>
#include <memory>
#include "../TestEvaluator.hpp"

using namespace std;
auto te = make_unique<TestEvaluator>();
class BankAccount
{
private:
    float _money = 0;

public:
    BankAccount()
    {
        _money = 0;
    };
    ~BankAccount(){};
    void setMoneyFounds(float money)
    {
        _money = money;
    };
    float getMoneyFounds()
    {
        return _money;
    }
};

// test para evaluar si una cuenta tiene dineros
/*void testBankAccountFounds()
{
    // arrange
    auto bankAccount = make_unique<BankAccount>();
   
    // act 
    bankAccount->setMoneyFounds(0);

    //assert
    te->evaluate("account funds test:", bankAccount->getMoneyFounds() > 0);
}*/
//Test para probar si la cuenta presenta deuda
void testBankAccountDebt()
{
    // arrange
    auto bankAccount = make_unique<BankAccount>();
   
    // act 
    bankAccount->setMoneyFounds(-101);
 

    //assert
    te->evaluate("account debt test:", bankAccount->getMoneyFounds()< 0);
}

int main(int argc, char const *argv[])
{
te->title("Bank account test:");

testBankAccountFounds();
testBankAccountDebt();

te->summary();  
    return 0;
}
