import os

# Modify this with your DSA-CP path if needed
base_dir = os.path.join(os.path.expanduser("~"), "DSA-CP", "StriverA2Z", "L19 Bit Manipulation")

template_code = '''#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
'''

problem_name = input("Enter problem name: ").strip().replace(" ", "_")
folder_path = os.path.join(base_dir, problem_name)

# Create folder and files
os.makedirs(folder_path, exist_ok=True)

cpp_path = os.path.join(folder_path, f"{problem_name}.cpp")
input_path = os.path.join(folder_path, "input.txt")
output_path = os.path.join(folder_path, "output.txt")

# Write files
with open(cpp_path, "w") as f:
    f.write(template_code)

open(input_path, "w").close()
open(output_path, "w").close()

print(f"✅ Created: {folder_path}")
