#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cstring>
#include <stdlib.h>
#include "stack.h"
using namespace std;

int main(int argc, char *argv[])
{
    Stack operand_1;
    Stack operand_2;
    Stack operand_3;
    Stack operand_4;
    Stack result1;
    Stack result2;
    int count1,count2,count3,count4;
    int countCompare;
    int storeFlag;
    int countresult2;
    int countresult1;
    int operandFlag;
    int point_error_flag;
    int arth_error_flag;
    int sum;
    int addingDecimalcarry;
    int addingCarry;
    int differCount;
    string operatorString;
    string temp;
    if(argc == 3)
    {
        point_error_flag = 0;
        arth_error_flag = 0;
        operandFlag = 0;
        storeFlag = 0;
        temp = argv[2];
        count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        countresult1 = 0;
        countresult2 = 0;
        addingCarry = 0;
        addingDecimalcarry = 0;
        countCompare = 0;
        differCount = 0;
        for(int i=0; i < temp.length(); i++)
        {
                if(isdigit(temp[i]))
                {
                    if(storeFlag == 0 && operandFlag == 0)
                    {
                        operand_1.push(temp[i] - '0'); // push in integar stack for 1st operand
                        count1++;
                    }
                    else if (storeFlag == 1 && operandFlag == 0)
                    {
                        operand_2.push(temp[i] - '0'); // push in decimal stack for 1st operand
                        count2++;
                    }
                    else if (storeFlag == 0 && operandFlag == 1)
                    {
                        operand_3.push(temp[i] - '0'); // push in integar stack for 2nd operand
                        count3++;
                    }
                    else if (storeFlag == 1 && operandFlag == 1)
                    {
                        operand_4.push(temp[i] - '0'); // push in the decimal stack for 2nd operand
                       count4++;
                    }
                }
                else if (temp[i] == '.' && i != 0)
                {
                    point_error_flag++;
                    storeFlag = 1;
                    if (point_error_flag > 1)
                    {
                        cout<<"Invalid input";
                        return 0;
                    }
                    else if(temp[i+1] == '+' || temp[i+1] == '-')
                    {
                        cout<<"Invalid input";
                        return 0;
                    }
                }
                else if (temp[i] == '+')
                {
                    arth_error_flag++;
                    operandFlag++;
                    operatorString = temp[i];
                    storeFlag = 0;
                    point_error_flag = 0;
                    if (arth_error_flag > 1)
                    {
                        cout<<"Invalid input";
                        return 0;
                    }
                }
                else
                {
                    cout<<"Invalid input";
                        return 0;
                }
        }


        ////////////////////////////////////////////add or subtract part///////////////////

        if(operatorString == "+")
        {
            if(operand_2.isEmpty() && operand_4.isEmpty())
            {
                NULL;
            }
            else
            {

            if (count2 > count4)
                {
                    countCompare = count2;
                    differCount = count2-count4;
                }
                else
                {
                    countCompare = count4;
                    differCount = count4 - count2;
                }
                if (count4 > count2 || count2 > count4)
                {
                    if(count2 > count4)
                    {
                        for(int i = 1; i <= differCount; i++)
                        {
                            sum = operand_2.pop();
                            result2.push(sum);
                            countresult2++;
                        }
                    }
                    else
                    {
                        for(int i =1; i <= differCount; i++)
                        {
                            sum = operand_4.pop();
                            result2.push(sum);
                            countresult2++;
                        }
                    }
                }
                    countCompare = countCompare - differCount;


                for(int i = 1; i<=countCompare; i++)
                {
                    sum = operand_2.pop()+operand_4.pop()+addingDecimalcarry;
                    if(sum-10 < 0)
                    {
                        result2.push(sum);
                        countresult2++;
                    }
                    else
                    {
                        if(i == countCompare)
                        {
                            addingCarry = 1;
                            result2.push(sum-10);
                            countresult2++;
                        }
                        else
                        {
                            addingDecimalcarry = 1;
                            result2.push(sum-10);
                            countresult2++;
                        }
                    }

                }
                }


                if (count1 > count3)
                {
                    countCompare = count1;
                }
                else
                {
                    countCompare = count3;
                }
                for(int i = 1; i <= countCompare; i++)
                {
                    if (operand_1.isEmpty())
                    {
                        sum = operand_3.pop() + addingCarry;
                    }
                    else if(operand_3.isEmpty())
                    {
                        sum = operand_1.pop() + addingCarry;
                    }
                    else
                    {
                    sum = operand_1.pop() + operand_3.pop() + addingCarry;
                    }
                    if (sum - 10 < 0)
                    {
                        result1.push(sum);
                        countresult1++;
                    }
                    else if(i == countCompare)
                    {
                        result1.push(sum);
                        countresult1++;
                    }
                    else
                    {
                        addingCarry = 1;
                        result1.push(sum-10);
                        countresult1++;
                    }
                }
                for(int i=1; i<=countresult1; i++)
                {
                    cout<<result1.pop();
                }
                if(result2.isEmpty())
                {
                    NULL;
                }
                else{
                    cout<<'.';
                }

                for(int i=1; i <= countresult2; i++)
                {
                    cout<<result2.pop();
                }

        }

    }
    else
    {
        cout<<"Invalid input";
        return 0;
    }

}





/*for(int j = 1; j <= differCount; j++)
                    {
                        if( i <= countCompare - differCount)
                        {
                        if (count2 > count4)
                        {
                            sum = addingDecimalcarry + operand_2.pop();
                            result2.push(sum);
                            countresult2;
                            i++;
                        }
                        else if (count4 > count2)
                        {
                            sum = addingDecimalcarry + operand_4.pop();
                            result2.push(sum);
                            countresult2;
                            i++;
                        }
                        else
                        {
                            sum = addingDecimalcarry + operand_2.pop() + operand_4.pop();
                            if (sum - 10 < 0)
                            {
                                result2.push(sum);
                                countresult2++;
                            }
                            else
                            {
                                if(i == countCompare)
                                {
                                    result2.push(sum-10);
                                    countresult2++;
                                    addingCarry = 1;
                                }
                                else
                                {
                                    addingDecimalcarry = 1;
                                    result2.push(sum-10);
                                    countresult2++;
                                }
                            }
                        }
                    }
                }*/
