#include <iostream>
using namespace std;



class Node
{
public:
    int data;
    Node* next;
    Node* previous;

    Node(int dataParametre)
    {
        this->data = dataParametre;
        this->next = NULL;
        this->previous = NULL;
    }
};


class CiftBagliDaireselListe
{
public:
    Node* root;

    CiftBagliDaireselListe()
    {
        this->root = NULL;
    }

    void ekle(int data)
    {
        Node* yeniDugum = new Node(data);
        if (root == NULL)
        {
            root = yeniDugum;
            root->next = root;
            root->previous = root;
        }
        else if (yeniDugum->data < root->data)
        {
            yeniDugum->next = root;
            yeniDugum->previous = root->previous;
            root->previous->next = yeniDugum;
            root->previous = yeniDugum;
            root = yeniDugum;
        }
        else
        {
            Node* iter = root;
            while (iter->next != root && iter->next->data < yeniDugum->data)
                iter = iter->next;
            yeniDugum->next = iter->next;
            yeniDugum->previous = iter;
            iter->next->previous = yeniDugum;
            iter->next = yeniDugum;
        }
    }

    void yazdir()
    {
        if (root == NULL)
        {
            cout << "Liste bos." << endl;
            return;
        }
        Node* iter = root;
        do
        {
            cout << iter->data << " ";
            iter = iter->next;
        } while (iter != root);
        cout << endl;
    }
};

int main()
{
    CiftBagliDaireselListe liste;
    for (int i = 0; i < 100; i++)
    {
        int rastgeleSayi = rand() % 499;
        liste.ekle(rastgeleSayi);
    }
    liste.yazdir();
    return 0;
}
