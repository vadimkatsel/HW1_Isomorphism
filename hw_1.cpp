#include <iostream>
#include <algorithm>

using namespace std;


const int N = 3;

/*Функция сравнения матриц*/
bool match(int A[N][N], int B[N][N], int* P) {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i][j] != B[P[i]][P[j]])           // найдено отличие - не совпадают
                return false;
    return true;                                    // отличий обнаружено не было - совпадают
}

/*Функция определения изоморфизма двух графов*/
bool isIsomorphic(int A[N][N], int B[N][N], int* P)
{
    do {
        if (match(A, B, P))
            return true;                           // найдена перестановка вершин графа B, при которой графы совпадают - изоморфны
    } while (next_permutation(P, P + N));

    return false;                                  // иначе - не изоморфны

}


int main()
{
    int P[N] = { 0,1,2 };
    int A[N][N] = { {0,1,1},{1,0,0},{1,0,0} };
    int B[N][N] = { {0,0,1},{0,0,1},{1,1,0} };

    cout << "A and B ";
    if (isIsomorphic(A, B, P))
        cout << "are isomorphic.";
    else
        cout << "arn`t isomorphic.";


}