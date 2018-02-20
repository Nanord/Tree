#include <iostream>

using namespace std;

struct tree
{
    int x;
    int sons; // количество потомков
    tree **son; //массив потомков дерева
};

void printTree(tree *p, int level,int &badlvl); // функция отображения дерева(badlvl по ссылке передём, чтобы само значение менялось, после входа в функцию)
void searchSubTrees(tree *p, int level, int badlvl, int needLevel); // функция выводит все поддеревья заданного диапазона
void add(tree *&node); // функция выводит все поддеревья заданного диапазона

int main()
{
    tree *root = NULL;
    add(root);

    int level = 0, // уровень
     badlvl = 0, // глубина дерева
     needLevel;// Диапазон поиска
    printTree(root, level,badlvl);
    cout << "==================" << endl;
    cout <<"Глубина дерева: "<< badlvl << endl;
    while(needLevel != 10) // цикл для тестов, уберешь его, когда надоест
    {
    cout <<"Введите диапозон: " << endl;
    cin >> needLevel;
    searchSubTrees(root, level, badlvl, needLevel);
    }
    return 0;
}

void printTree(tree *p, int level,int &badlvl)
{
    if (level>badlvl)
        badlvl = level;
    if (p)
    {
        for (int i = 0; i < level; i++) cout << "   ";
        cout << p->x << endl;
        if (p->sons)
        {
            for (int i = 0; i < p->sons; i++)
            {
                printTree(p->son[i], level + 1, badlvl);
            }
        }
    }
}

void searchSubTrees(tree *p, int level, int badlvl, int needLevel)
{
    if (p)
    {
        if (level < needLevel)
        {
            if (p->sons)
            {
                for (int i = 0; i < p->sons; ++i)
                {
                    searchSubTrees(p->son[i], level + 1, badlvl, needLevel);
                }
            }
        }
        else printTree(p, level, badlvl);
    }
}



void add(tree *&node)x
{
    int x, s;
    if (node == NULL)
    {
        node = new tree;

        cout << "Введите значение узла " << endl;
        cin >> x;
        cout << "Введите количество сыновей" << endl;
        cin >> s;
        node->x = x;
        node->sons = s;
        node->son = new tree*[s];
        if (s)
        {
            cout << "***************" << endl;
            for (int i = 0; i < s; i++)
                node->son[i] = NULL;
            for (int i = 0; i < s; i++)
            {
                add(node->son[i]);
            }
            cout << "***************" << endl;
        }
    }
}