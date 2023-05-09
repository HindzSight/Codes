#include <iostream>

using namespace std;
#include <unordered_set>
#include <vector>

void lru(string s, int frame_size)
{
    int n = s.length();

    vector<int> frame;
    int hit = 0;
    for (int i = 0; i < n; i++)
    {

        int current_value = int(s[i]) - 48;

        int flag = 0;
        for (int j = 0; j < frame.size(); j++)
        {
            if (frame[j] == current_value)
            {
                cout << "Hit for value " << current_value << endl;
                flag = 1;
                hit += 1;
                break;
            }
        }
        if (flag == 1)
        {
            // hit condition
            continue;
        }

        unordered_set<int> set;
        int third_unique = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            int temp = int(s[j]) - 48;
            set.insert(temp);

            if (set.size() == frame_size)
            {
                third_unique = temp;
                break;
            }
        }

        if (third_unique == -1)
        {
            frame.push_back(current_value);
        }
        else
        {
            for (int j = 0; j < frame.size(); j++)
            {
                if (frame[j] == third_unique)
                {
                    frame[j] = current_value;
                    break;
                }
            }
        }

        cout << "Frame:: ";
        for (int j = 0; j < frame.size(); j++)
        {
            cout << frame[j] << " ";
        }
        cout << endl;
    }
    cout << "Page Fault : " << n - hit << endl;
}

int main()
{

    int n;
    string ref_string;
    cout << "Enter the reference string" << endl;
    cin >> ref_string;
    cout << "Enter the frame number" << endl;
    cin >> n;

    lru(ref_string, n);

    return 0;
}
//ref_str : 70120304230321201701