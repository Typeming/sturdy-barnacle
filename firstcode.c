#include<iostream>
#include<vector>
#include<queue>
#define MAX 100
typedef char Exper;

using namespace std;

typedef struct {
    Exper head[MAX];
    int v;
}Graph;

typedef struct {
    int num;
    Exper a, b;
}Node;

typedef struct {
    Node N[MAX];
}All;

void Sort(All* A, int a) {
    for (int i = 1; i < a; i++) {
        int j = i - 1;
        int t1 = A->N[i].num;
        char t2 = A->N[i].a;
        char t3 = A->N[i].b;
        while (j >= 0 && t1 < A->N[j].num) {
            A->N[j + 1].num = A->N[j].num;
            A->N[j + 1].a = A->N[j].a;
            A->N[j + 1].b = A->N[j].b;
            j--;
        }
        A->N[j + 1].num = t1;
        A->N[j + 1].a = t2;
        A->N[j + 1].b = t3;
    }
}

int Find(Graph* G, Exper a) {
    for (int i = 0; i < G->v; i++) {
        if (a == G->head[i]) {
            return i;
        }
    }
}

int Kruskal(Graph* G, All* A, int a) {
    int arr[MAX], ass[MAX];
    for (int i = 0; i < G->v; i++)
        arr[i] = i;
    for (int i = 0; i < G->v; i++)
        ass[i] = 0;
    for (int i = 0; i < a; i++) {
        int t1 = Find(G, A->N[i].a);
        int t2 = Find(G, A->N[i].b);
        if (arr[t1] != arr[t2]) {
            int tem = arr[t2];
            for (int j = 0; j < G->v; j++) {
                if (arr[j] == tem) {
                    arr[j] = arr[t1];
                }
            }
            int temp = ass[t1] + ass[t2] + A->N[i].num;
            for (int j = 0; j < G->v; j++) {
                if (arr[j] == arr[t1]) {
                    ass[j] = temp;
                }
            }
        }
    }

    return ass[arr[0]];
}

int main() {
    Graph G;
    cin >> G.v;
    for (int i = 0; i < G.v; i++) {
        cin >> G.head[i];
    }
    All A;
    int i = 0;
    char a, b;
    while (cin >> a >> b) {
        A.N[i].a = a;
        A.N[i].b = b;
        cin >> A.N[i].num;
        i++;
    }
    Sort(&A, i);
    cout << Kruskal(&G, &A, i) << endl;

    return 0;
}
/*
8
1 2 3 4 5 6 7 8
1 2 12
1 5 2
2 8 5
2 6 3
6 7 7
4 7 8
3 4 8
3 5 2
3 6 4
4 5 10
*/


