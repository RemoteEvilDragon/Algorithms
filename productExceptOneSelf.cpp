 vector<int> results;
        
int acc=1;
for(int i=1;i<=num;i++)
{
    acc *= i;
    results.push_back(acc);
}

int zeroOne = results.at((int)results.size()-1);

int parameter = 1;

for(int i=(int)results.size()-1;i>=1;i--)
{
        if( i == (int)results.size()-1)
        {
            results.at(i) = results.at(i-1);
        }
        else
        {
            results.at(i) = results.at(i-1)*parameter+results.at(i+1);
            
            parameter *= (i+2);
        }
}

results.at(0) = zeroOne;

return results;