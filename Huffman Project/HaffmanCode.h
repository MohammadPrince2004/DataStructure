#include "MinHeap.h"
#include "HashMap.h"
#include "HuffmanNode.h"
using namespace std;

class HuffmanTree
{
private:
    void GenerateCodes(HuffmanNode *node, string code)
    {
        if (node == NULL)
            return;
        if ((node->left == NULL) && (node->right == NULL))
        {
            if(code == "")
                code = "0";
            codeMap.Insert(node->character, code);
            return;
        }
        GenerateCodes(node->left, code + "0");
        GenerateCodes(node->right, code + "1");
    }

public:
    HuffmanNode *root;
    HashMap<int> freqMap;
    MinHeap heap;
    HashMap<string> codeMap;
    void BuildFrequencyMap(string text)
    {
        for (int i = 0; i < text.length(); i++)
        {
            freqMap.Insert(text[i], freqMap.Get(text[i]) + 1);
        }
    }
    void BuildHeap()
    {
        for (int i = 0; i < SIZE; i++)
        {
            char c = (char)i;
            int freq = freqMap.Get(c);
            if (freq > 0)
            {
                HuffmanNode *node = new HuffmanNode(c, freq);
                heap.Insert(node);
            }
        }
    }
    void BuildTree()
    {
        while (heap.getSize() > 1)
        {
            HuffmanNode *leftNode = heap.ExtractMin();
            HuffmanNode *rightNode = heap.ExtractMin();
            HuffmanNode *parentNode = new HuffmanNode('\0', leftNode->frequency + rightNode->frequency);
            parentNode->left = leftNode;
            parentNode->right = rightNode;
            heap.Insert(parentNode);
            cout << "Merging: " << leftNode->character << "(" << leftNode->frequency << ") with " 
     << rightNode->character << "(" << rightNode->frequency << ")" << endl;
        }
        root = heap.ExtractMin();
    }

    void GenerateCodes()
    {
        GenerateCodes(root, "");
    }

    string Encode(string text)
    {
        
        string code = "";
        for (int i = 0; i < text.length(); i++)
        {
            code = code + "  " + codeMap.Get(text[i]);
        }
        return code;
    }
};