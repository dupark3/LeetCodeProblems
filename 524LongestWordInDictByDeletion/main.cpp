#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sortBySize(const string& s1, const string& s2){
    if (s1.size() == s2.size()){
        return s1 < s2;
    } else {
        return s1.size() > s2.size();
    }
}

class Solution {
public:
    string findLongestWord(const string& s, vector<string>& d) {
        sort(d.begin(), d.end(), sortBySize);
        // monkey, apple, plea, plee, ale
        // abpcplea
        int wordSize = s.size();
        int dictSize = d.size();

        for (int i = 0; i != dictSize; ++i){
            // cout << "Checking " << d[i] << endl;
            int index = 0;
            int dictwordSize = d[i].size();
            for (int j = 0; j != dictwordSize; ++j){
                // cout << "   checking " << d[i][j] << endl;
                int charIndex = s.find(d[i][j], index);
                if (charIndex != -1){
                    // cout << "       found char " << d[i][j] << " at " << charIndex << endl;
                    index = charIndex + 1;
                    if (j == dictwordSize - 1){
                        return d[i];
                    }
                } else {
                    break;
                }
            }
        }
        return "";
    }
};

int main(){
    Solution solution;
    string word = "wsmzffsupzgauxwokahurhhikapmqitytvcgrfpavbxbmmzdhnrazartkzrnsmoovmiofmilihynvqlmwcihkfskwozyjlnpkgdkayioieztjswgwckmuqnhbvsfoevdynyejihombjppgdgjbqtlauoapqldkuhfbynopisrjsdelsfspzcknfwuwdcgnaxpevwodoegzeisyrlrfqqavfziermslnlclbaejzqglzjzmuprpksjpqgnohjjrpdlofruutojzfmianxsbzfeuabhgeflyhjnyugcnhteicsvjajludwizklkkosrpvhhrgkzctzwcghpxnbsmkxfydkvfevyewqnzniofhsriadsoxjmsswgpiabcbpdjjuffnbvoiwotrbvylmnryckpnyemzkiofwdnpnbhkapsktrkkkakxetvdpfkdlwqhfjyhvlxgywavtmezbgpobhikrnebmevthlzgajyrmnbougmrirsxi";
    vector<string> dictionary = {"jpthiudqzzeugzwwsngebdeai","nbmxgkduynigvzuyblwjepn","ale","plea","plee"};
    cout << solution.findLongestWord(word, dictionary) << endl;
    return 0;
}