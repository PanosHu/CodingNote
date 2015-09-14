#include <iostream>
#include <vector>
using namespace std;

bool find_Char(const vector<vector<char> > &vec, char ch, int &row, int &col)
{
    for(vector<char>::size_type r = 0; r != vec.size(); ++r)
    {
        for(vector<char>::size_type c = 0; c != vec[r].size(); ++c)
        {
            if(vec[r][c] == ch)
            {
                row = r;
                col = c;
                return true;
            }
        }
    }
    return false;
}

bool find_path(vector<vector<char> > &vec, vector<char>::size_type row, vector<char>::size_type col, char target)
{
    if(row < 0 || col < 0 || row >= vec.size()
       || col >= vec[vec.size()-1].size())
    {
        return false;
    }

    if(vec[row][col] == target)
    {
        return true;
    }

    if(vec[row][col] == '#')
    {
        return false;
    }

    char temp = vec[row][col];
    vec[row][col] = '#';

    if( find_path(vec, row, col-1, target) )
        return true;
    if( find_path(vec, row, col+1, target) )
        return true;
    if( find_path(vec, row-1, col, target) )
        return true;
    if( find_path(vec, row+1, col, target) )
        return true;

    vec[row][col] = temp;
    return false;
}

int main()
{
    vector<char>::size_type row(0),col(0);
    cin>>row>>col;

    vector<vector<char> > vec_map(row);
    for(vector<char>::size_type r = 0; r != row; ++r)
    {
        vec_map[r].resize(col);
        for(vector<char>::size_type c =0; c != col; ++c)
        {
            char cVar(0);
            cin>>cVar;
            vec_map[r][c] = cVar;
        }
    }

    int row_B(0), col_B(0);
    char result = 'N';
    if(find_Char(vec_map, 'B', row_B, col_B))
    {
        result = find_path(vec_map, row_B, col_B, 'H')?'Y':'N';
    }
    cout<<result<<endl;

    return 0;
}
