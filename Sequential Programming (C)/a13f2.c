#include <stdio.h>
#include <simpio.h>

int main(){

/*� assistantforModulo ��������������� ��� �� ������ �� �������
�� �� �������� ����� ��� ����� ��� ������� ����� ������ �����
��� �� ���������� ��� �������� �� ���� ����� ����� �����������
�� �������
*/

int numberOfCoffees,withoutDecimal,assistantforModulo;
float change,decimal;

printf("Dose kafedes:");
numberOfCoffees = GetInteger();

change = 5 - numberOfCoffees * 0.7;
decimal = change - (int)change;
withoutDecimal = (int)change;

if(numberOfCoffees * 0.7 <= 5){
    printf("Resta");
    printf("Kermata 2E:%d\n",withoutDecimal/2);
    withoutDecimal %= 2;
    printf("Kermata 1E:%d\n",withoutDecimal/1);
    assistantforModulo = decimal * 10;
    printf("Kermata 50L:%d\n",assistantforModulo/5);
    assistantforModulo %= 5;
    printf("Kermata 20L:%d\n",assistantforModulo/2);
    assistantforModulo %=2;
    printf("Kermata 10L:%d\n",assistantforModulo);
}
}
