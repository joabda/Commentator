#include "Header.h"

Header::Header()
{
    cout << "Company's name: ";
    cin >> company_;
    cout << endl;

    cout << "Project's name: ";
    cin >> project_;
    cout << endl;
    
    copyrights();

    cout << "Code's Owner: ";
    cin >> owner_;
    cout << endl;

}

void Header::copyrights()
{
    int licenseChoice = 0;
    const string availableLicenses[4] = {"MIT License", "Appache License 2.0",
        "GNU General Public License v3.0", "Unlicensed"};

    while(licenseChoice < 1 || licenseChoice > 4)
    {
        cout << "1 - " << availableLicenses[0] << endl;
        cout << "2 - " << availableLicenses[1] << endl;
        cout << "3 - " << availableLicenses[2] << endl;
        cout << "4 - " << availableLicenses[3] << endl;
        cin >> licenseChoice;
    }
    license_ = availableLicenses[licenseChoice - 1];
}

string Header::getText() const
{
   return 
   "/* "
    "* This file is part of" + project_ + ".\n"
    "*\n"
    "* This product includes software developed by " + company_ + "\n"
    "* This product is owned by " + owner_ + " under the " + license_ + "\n"
    "* This program is distributed in the hope that it will be useful,\n"
    "* See the GNU General Public License for more details.\n"
    "*\n"
    "* You should have received a copy of the License along with this program.\n"
    "*/\n";
}
