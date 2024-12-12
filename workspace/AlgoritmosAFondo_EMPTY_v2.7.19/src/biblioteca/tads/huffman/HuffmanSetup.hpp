

#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "../tads/parte2/Stack.hpp"
using namespace std;

struct HuffmanTable
{
   unsigned int n;
   string cod;
};

// Info de los nodos del arbol
struct HuffmanTreeInfo
{
   unsigned int c;
   unsigned int n;
   HuffmanTreeInfo* left;
   HuffmanTreeInfo* right;
};

HuffmanTreeInfo* huffmanTreeInfo(int c, long n, HuffmanTreeInfo* left, HuffmanTreeInfo* right)
{
   HuffmanTreeInfo* node = new HuffmanTreeInfo();
   node->c=c;
   node->n=n;
   node->left=left;
   node->right=right;
   return node;
}


// ---------------------
// -- TAD HuffmanTree --

struct HuffmanTree
{
   Stack<HuffmanTreeInfo*> pila;
   Stack<string> pilaCod;
};

// init function
HuffmanTree huffmanTree(HuffmanTreeInfo* root)
{
   HuffmanTree tu;
   tu.pila = stack<HuffmanTreeInfo*>();
   tu.pilaCod = stack<string>();
   stackPush<HuffmanTreeInfo*>(tu.pila,root);
   stackPush<string>(tu.pilaCod,"");
   return tu;
}

bool huffmanTreeHasNext(HuffmanTree ht)
{
   return !stackIsEmpty<HuffmanTreeInfo*>(ht.pila);
}

HuffmanTreeInfo* huffmanTreeNext(HuffmanTree& tu,string& cod)
{
   bool hoja=false;
   HuffmanTreeInfo* p = NULL;
   HuffmanTreeInfo* aux = NULL;
   string zz;

   while( !stackIsEmpty<HuffmanTreeInfo*>(tu.pila) && !hoja )
   {
      p = stackPop<HuffmanTreeInfo*>(tu.pila);
      zz = stackPop<string>(tu.pilaCod);

      if( p->right!=NULL )
      {
         stackPush<HuffmanTreeInfo*>(tu.pila,p->right);
         aux = new HuffmanTreeInfo();
         aux->n = 1;
         stackPush<string>(tu.pilaCod,zz+"1");
      }

      if( p->left!=NULL )
      {
         stackPush<HuffmanTreeInfo*>(tu.pila,p->left);
         aux = new HuffmanTreeInfo();
         aux->n = 0;
         stackPush<string>(tu.pilaCod,zz+"0");
      }

      if( p->left==NULL && p->right==NULL)
      {
         hoja = true;
         cod.clear();
         cod.append(zz);
      }
      else
      {
         p = NULL;
      }
   }

   return p;
}

HuffmanTreeInfo* huffmanTreeCreateDemoTree()
{
   // nivel 5 (ultimo nivel)
   HuffmanTreeInfo* nS = huffmanTreeInfo('S', 1, NULL, NULL);
   HuffmanTreeInfo* nR = huffmanTreeInfo('R', 1, NULL, NULL);
   HuffmanTreeInfo* nN = huffmanTreeInfo('N', 1, NULL, NULL);
   HuffmanTreeInfo* nI = huffmanTreeInfo('I', 1, NULL, NULL);

   // nivel 4
   HuffmanTreeInfo* a2 = huffmanTreeInfo(256+2, 2, nS, nR);

   HuffmanTreeInfo* a1 = huffmanTreeInfo(256+1, 2, nN, nI);
   HuffmanTreeInfo* nT = huffmanTreeInfo('T', 2, NULL, NULL);
   HuffmanTreeInfo* nE = huffmanTreeInfo('E', 2, NULL, NULL);
   HuffmanTreeInfo* nA = huffmanTreeInfo('A', 2, NULL, NULL);
   HuffmanTreeInfo* nU = huffmanTreeInfo('U', 1, NULL, NULL);

   // nivel 3
   HuffmanTreeInfo* nC = huffmanTreeInfo('C', 7, NULL, NULL);
   HuffmanTreeInfo* nM = huffmanTreeInfo('M', 5, NULL, NULL);
   HuffmanTreeInfo* nESP = huffmanTreeInfo(' ', 5, NULL, NULL);
   HuffmanTreeInfo* a5 = huffmanTreeInfo(256+5, 4, a2, a1);
   HuffmanTreeInfo* a4 = huffmanTreeInfo(256+4, 4, nT, nE);
   HuffmanTreeInfo* a3 = huffmanTreeInfo(256+3, 3, nA, nU);

   // nivel 2
   HuffmanTreeInfo* a8 = huffmanTreeInfo(256+8, 12, nC, nM);
   HuffmanTreeInfo* nO = huffmanTreeInfo('O', 11, NULL, NULL);
   HuffmanTreeInfo* a7 = huffmanTreeInfo(256+7, 9, nESP, a5);
   HuffmanTreeInfo* a6 = huffmanTreeInfo(256+6, 7, a4, a3);

   // nivel 1
   HuffmanTreeInfo* a10 = huffmanTreeInfo(256+10, 23, a8, nO);
   HuffmanTreeInfo* a9  = huffmanTreeInfo(256+9, 16, a7, a6);

   // nivel 0 (raiz)
   HuffmanTreeInfo* a11 = huffmanTreeInfo(256+11, 39, a10, a9);

   return a11;
}

void huffmanTreeDemo()
{
   // obtengo el arbol
   HuffmanTreeInfo* root = huffmanTreeCreateDemoTree();

   // recorro el arbol usando TAD HuffmanTree
   HuffmanTree ht = huffmanTree(root);

   string cod;
   while( huffmanTreeHasNext(ht) )
   {
      HuffmanTreeInfo* x = huffmanTreeNext(ht,cod);
      cout << x->c << ", ("<<x->n <<"), " << "[" << cod <<"]" << endl;
   }
}



#endif
