#include<cstdlib>
#include<iostream>

using namespace std;
main()
{
    float a,b,c,d,e,p;
    cout<<"Enter the fiv subjects marks: ";
    cin>>a>>b>>c>>d>>e;
    p=((a+b+c+d+e)/500)*100;

    if (p>=80)
    {
        cout<<"Grade is A"<<endl;
    }
    else
    {
        if (p>=65)
        {
            cout<<"Grade is B"<<endl;
            }
            else
            {
                if (p>=55)
                {
                    cout<<"Grade is c"<<endl;
                }
                else{
                    if (p>=40)
                    {
                        cout<<"Grade is D"<<endl;
                    }
                    
                    else
                    {
                        cout<<"Failed!"<<endl;
                    }
                }
            }
            
        }
        
    }
    
