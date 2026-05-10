#include "HaffmanCode.h"


int main()
{
    // HuffmanTree huffman;

    // cout << "=== Test 1===" << endl;
    // string text = "mohammad";
    // cout << "Original Text" << text << endl;

    // huffman.BuildFrequencyMap(text);
    // huffman.BuildHeap();
    // huffman.heap.Display();
    // huffman.BuildTree();
    // huffman.GenerateCodes();

    // cout << "\n Codes:" << endl;
    // cout << "'m' : " << huffman.codeMap.Get('m') << endl;
    // cout << "'o' : " << huffman.codeMap.Get('o') << endl;
    // cout << "'h' : " << huffman.codeMap.Get('h') << endl;
    // cout << "'a' : " << huffman.codeMap.Get('a') << endl;
    // cout << "'d' : " << huffman.codeMap.Get('d') << endl;

    // cout << "\n Encoded: " << huffman.Encode(text) << endl;

    HashMap<int> hashmap;
    hashmap.Insert('a',10);
    hashmap.Insert('b',5);
    hashmap.Insert('c',8);
    hashmap.Display();
    hashmap.Remove('b');
    hashmap.Display();

    
}
// 