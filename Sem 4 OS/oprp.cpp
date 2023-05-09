
#include <iostream>
#include <climits>
using namespace std;
#include <unordered_set>
#include <vector>

void oprp(string s, int frame_size)
{
    int n = s.length();

    int hit_count = 0;
    vector<int> frame;
    for (int i = 0; i < n; i++)
    {

        int current_value = int(s[i]) - 48;

        int flag = 0;
        for (int j = 0; j < frame.size(); j++)
        {
            if (frame[j] == current_value)
            {
                cout << "Hit for value " << current_value << endl;
                hit_count += 1;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            // hit condition
            continue;
        }

        if (frame.size() < frame_size)
        {
            frame.push_back(current_value);
        }
        else
        {
            vector<int> index;
            int flag2 = 0;
            for (int k = 0; k < frame.size(); k++)
            {
                int ele = frame[k];
                int ele_index = INT_MAX;
                flag2 = 0;
                for (int j = i + 1; j < n; j++)
                {
                    int temp1 = int(s[j]) - 48;
                    if (temp1 == ele)
                    {
                        index.push_back(j);
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 0)
                {
                    index.push_back(INT_MAX);
                }
            }

            int maximum_index = -1;
            int maximum_index_value = -1;
            for (int j = 0; j < index.size(); j++)
            {
                if (index[j] > maximum_index_value)
                {
                    maximum_index_value = index[j];
                    maximum_index = j;
                }
            }

            int ele1 = int(s[maximum_index]) - 48;
            frame[maximum_index] = current_value;
        }

        cout << "Frame:: ";
        for (int j = 0; j < frame.size(); j++)
        {
            cout << frame[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Page Fault:: " << n - hit_count << endl;
}

int main()
{

    int n;
    string ref_string;
    cout << "Enter the reference string" << endl;
    cin >> ref_string;
    cout << "Enter the frame number" << endl;
    cin >> n;

    oprp(ref_string, n);

    return 0;
}

//ref_str : 70120304230321201701
