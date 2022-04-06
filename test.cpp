#include <iostream>
#include <fstream>

using namespace std;


int StrCmp(char*,char*);

int main ()
{

    char input[255];
    char output[255];
    int ReductionFactor=0;
    cout<<"enter input filename"<<endl;
    cin>>input;
    ifstream fin;
    cout<<input<<endl;
    fin.open(input);
    cout<<"enter output filename"<<endl;
    cin>>output;
    ofstream fout;
    fout.open(output);
    cout<<"enter reduction factor"<<endl;
    cin>>ReductionFactor;

    float DataFloatValue[11]={0};
    int SizeX=1,SizeY=1;
    float CoorMAX[2]={0};
    int total_point=0;

// Phase   X  Y Bands   Error  Eu1  Eu2  Eu3  MAD  BC   BS
   while(!fin.eof())
    {
        char title[512]={0};
        fin.getline(title,512);
   
       if(title[6]=='X')
        {
            break;
        }
    }
    while(!fin.eof())
    {
        fin>>DataFloatValue[0]>>DataFloatValue[1]>>DataFloatValue[2]>>DataFloatValue[3]>>DataFloatValue[4]>>DataFloatValue[5]>>DataFloatValue[6]>>DataFloatValue[7]>>DataFloatValue[8]>>DataFloatValue[9]>>DataFloatValue[10];
        if(DataFloatValue[1]>CoorMAX[0])
        { CoorMAX[0]=DataFloatValue[1]; SizeX+=1;}
        if(DataFloatValue[2]>CoorMAX[1])
        { CoorMAX[1]=DataFloatValue[2]; SizeY+=1;}
    }
    fin.close();
    float*** DataArray;
    DataArray = new float** [SizeY];
    for(int i=0;i<SizeY;i+=1)
    {
        *(DataArray+i) = new float* [SizeX];
        for(int j=0;j<SizeX;j+=1)
        {
            *(*(DataArray+i)+j) = new float [11];
            for(int k=0;k<11;k+=1)
            {

                *(*(*(DataArray+i)+j)+k)=0;
            
            }

        }
    }
    fin.open(input);
   while(!fin.eof())
    {
        char title[512]={0};
        fin.getline(title,512);
        fout<<title<<endl;
       if(title[6]=='X')
        {
            break;
        }
    }
      //  cout<<"4"<<endl;
    while(!fin.eof())
    {

        for(int i=0;i<SizeY;i+=1)
        {
            for(int j=0;j<SizeX;j+=1)
            {
                
                for(int k=0;k<=10;k+=1)
                {
                    fin>>DataArray[i][j][k];
                }
            }
         
        }
    }
   
int newY=0;
int newX=0;
fin.close();

     for(int i=0;i<SizeY;i+=ReductionFactor)
    {
        newY+=1;
        for(int j=0;j<SizeX;j+=ReductionFactor)
        { 
            if(i==0)
            {
                newX+=1;
            }
            fout<<DataArray[i][j][0]<<"\t"<<DataArray[i][j][1]<<"\t"<<DataArray[i][j][2]<<"\t"<<DataArray[i][j][3]<<"\t"<<DataArray[i][j][4]<<"\t"
                <<DataArray[i][j][5]<<"\t"<<DataArray[i][j][6]<<"\t"<<DataArray[i][j][7]<<"\t"<<DataArray[i][j][8]<<"\t"<<DataArray[i][j][9]<<"\t"
                <<DataArray[i][j][10]<<endl;
        }
    }
    fout.close();
    cout<<"new X="<<newX<<'\t'<<"newY="<<newY<<endl;

    system("pause");

    return 0;
}
