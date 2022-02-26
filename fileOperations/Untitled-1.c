/* Binary Search Tree (BST) Implementation
*  Insert only for now ;)
*  Data Structures & Algorithms Course
*  Dr. Aykut Guven
*  Beykent University Computer Engineering Department
*/

#include <iostream>
using namespace std;


struct TreeNode
{
    int Data;
    TreeNode* Left;
    TreeNode* Right;
};

int main()
{
    TreeNode* Root = NULL;
    int menu = 0;

    while (menu != -1)
    {
        cout << "1- Agaca eleman ekle" << endl;
        cout << "2- Agaci yazdir" << endl;
        cout << "3- Cikis" << endl;
        cout << "Seciminiz?";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            TreeNode* Node = new TreeNode();
            cout << "Eklenecek degeri giriniz : ";
            cin >> Node->Data;

            /*
                Eğer Root NULL ise Node Root olmalı
                Root NULL değilse, Node'un ekleneceği Parent Node'u bul.
                Uygun bir Node var ise Büyük ya da küçük durumuna göre Parent Node'un sağğına ya da soluna yeni Node'u ekle.
            */

            if (Root == NULL)
                Root = Node;
            else
            {
                TreeNode* CurrentNode = Root;
                bool isAdded = false;
                while (!isAdded)
                {
                    if (Node->Data > CurrentNode->Data)
                    {
                        if (CurrentNode->Right == NULL)
                        {
                            CurrentNode->Right = Node;
                            isAdded = true;
                            //CurrentNode = CurrentNode->Right;

                        }
                        else
                        {
                            CurrentNode = CurrentNode->Right;
                        }

                    }
                    else
                    {
                        if (CurrentNode->Left == NULL)
                        {
                            CurrentNode->Left = Node;
                            isAdded = true;
                        }
                        else
                        {
                            CurrentNode = CurrentNode->Left;

                        }

                    }

                }
            }

        }
        break;
        case 2:
            cout << "Agacin durumu" << endl;
        }
    }
}

