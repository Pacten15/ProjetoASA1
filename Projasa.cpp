#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> readVector()
{
    uint number;
    vector<int> v;
    while(cin >> number)
    {
        v.push_back(number);
        if(cin.peek() == '\n' || cin.peek() == '\0')
            break;
    }
    return v;
}



vector<int> readSecondVector(vector<int> v)
{
    uint number;
    vector<int> v2;
    vector<int> vazio = {};
    while(cin >> number)
    {
        if(find(v.begin(),v.end(),number) != v.end())
        {
            v2.push_back(number);
        }
        if(cin.peek() == '\n' || cin.peek() == '\0')
        {
            break;
        }
    }
    if(v2.size() > 0)
        return v2;
    else
        return vazio;
}


void printVector(vector<int> v1)
{
    for(uint i=0;i<v1.size();i++)
    {
        cout << v1[i] << " ";

    }
    cout << '\n';
}

vector<int> removeNonCommun(vector<int> v1,vector<int> v2)
{
    vector<int> result;
    for(uint i=0;i<v1.size();i++)
    {
        if(find(v2.begin(),v2.end(),v1[i]) != v2.end())
        {
            result.push_back(v1[i]);
        }
    }
    return result;
}

vector<int> deleteElementbyIndex(vector<int> v,uint index)
{
    vector<int> newVec;
    for(uint i=0;i<v.size();i++)
    {
        if(i != index)
        {
            newVec.push_back(v[i]);
        }
    }
    return newVec;
}

vector<int> sortVector(vector<int> v)
{
    for(uint i=0;i<v.size();i++)
    {
        for(uint j=i;j<v.size();j++)
        {
            if(v[i] >= v[j])
            {
                swap(v[i],v[j]);
            }
        }
    }
    return v;
}

vector<int> inicializesubVectorwithValue(uint sizeVector,int value)
{
    vector<int> vector1;
    for(uint i=0;i<sizeVector;i++)
    {
        vector1.push_back(value);
    }
    return vector1;
}


int maxValueVector(vector<int> v)
{
    int max = v[0];
    for(uint i=0;i<v.size();i++)
    {
        if(v[i]>max)
        {
            max = v[i];
        }
    }
    return max;
}

vector<int> vectorIndexSameValue(vector<int> v,int value)
{
    vector<int> indexSameValue;
    for(uint i=0;i<v.size();i++)
    {
        if(v[i]==value)
        {
            indexSameValue.push_back(i);
        }
    }
    return indexSameValue;
}

vector<int> maxNSubSeq(vector<int> v)
{
    vector<int> count_MaxlenghtsbyIndex = inicializesubVectorwithValue(v.size(),1);
    vector<int> maxlenghtsubs = inicializesubVectorwithValue(v.size(),1);
    int maxLIS=0;
    int nMaxISub=0;
    for(uint j=1;j<v.size();j++)
    {
        int lis_index =1;
        int n_lis_index =1;
        for(uint i=0;i<j;i++)
        {
            if(v[i]<v[j])
            {
                if(maxlenghtsubs[i]+1>lis_index)
                {
                    lis_index = maxlenghtsubs[i]+1;
                    n_lis_index = count_MaxlenghtsbyIndex[i];
                }
                else if(maxlenghtsubs[i]+1 == lis_index)
                {
                    n_lis_index += count_MaxlenghtsbyIndex[i];
                }
            }
        }
        maxlenghtsubs[j] = lis_index;
        count_MaxlenghtsbyIndex[j] = n_lis_index;
        if(lis_index > maxLIS)
        {
            maxLIS=lis_index;
            nMaxISub = n_lis_index;
        }
        else if(lis_index == maxLIS)
        {
            nMaxISub += n_lis_index;
        }
    }
    if (maxLIS > 1)
    {
        return {maxLIS,nMaxISub};
    }
    if(maxLIS == 1)
    {
        return {maxLIS,nMaxISub+1};
    }
    else 
        return {1,1};
    
}

unordered_map<int,int> readVectorToMap(vector<int> v)
{
    unordered_map<int,int> unmap;
    for(uint i=0;i<v.size();i++)
    {
        unmap[v[i]] = 1;
    }
    return unmap;
}

void printmap(unordered_map<int,int> const &unmap)
{
    for(auto const &pair: unmap)
    {
       std::cout << "{" << pair.first << ": " << pair.second << "}\n"; 
    }
}

vector<int> readsecondVectorusingMap(unordered_map<int,int> unmap)
{
    uint number;
    vector<int> v2;
    vector<int> vazio = {};
    while(cin >> number)
    {
    
        if(unmap.find(number) != unmap.end())
        {
            v2.push_back(number);
        }
        if(cin.peek() == '\n' || cin.peek() == '\0')
        {
            break;
        }
    }
    return v2;
}






int nCommunSubSeq(vector<int> v1)
{
    
    unordered_map<int,int> same_value_counter = readVectorToMap(v1);
    vector<int> v2 = readsecondVectorusingMap(same_value_counter);
    int sizeV2 = v2.size();
    int resultadoCorrente;
    
    vector<int> registoCorrente = inicializesubVectorwithValue(v2.size(),0);
    if (v2.size() > 0)
    {
        vector<int> v3 = removeNonCommun(v1,v2);
        int sizeV3 = v3.size();

        for(int i=0;i<sizeV3;i++)
        {
            resultadoCorrente=0;
            for(int j=0;j<sizeV2;j++)
            {
                if(v3[i]==v2[j])
                {
                    if(resultadoCorrente + 1 > registoCorrente[j])
                    {
                        registoCorrente[j] = resultadoCorrente + 1;
                    }
                }
                else if(v3[i] > v2[j])
                {
                    if(registoCorrente[j]>resultadoCorrente)
                    {
                        resultadoCorrente = registoCorrente[j];
                    }
                }
            }
        }
        int resultado = maxValueVector(registoCorrente);
        return resultado;
        
    }
    else
        return 0;
}





int main()
{
    int choice;
    int work = scanf("%d\n", &choice);
    vector<int> v = readVector();
    if(choice == 1 && work==1)
    {
        
        vector<int> result = maxNSubSeq(v);
        printf("%d %d\n", result[0],result[1]);
        
    }
    else if(choice ==2 && work==1)
    {
        int result = nCommunSubSeq(v);
        printf("%d\n", result);
    }
}
    
 