#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class URL {
    private:
        std::string scheme, authority, path;
    public:
        URL(std::string url) {
            int pos, pos2, pos3, num;
            pos = url.find(":");

			for (int i = 0; i < url.size(); i++) {
				if (url[i] == '/' && url[i + 1] == '/') {
					pos2 = i;
					i++;
				}
				else if (url[i] == '/' && url[i + 1] != '/') {
					pos3 = i;
					break;
				}
			}

			scheme = url.substr(0, pos + 1);

			num = ((url.size() - pos) - (url.size() - pos3)) - 1;
			authority = url.substr(pos2, num);

			path = url.substr(pos3);
        }

		std::string getScheme() {
			return scheme;
		}

		std::string getAuthority() {
			return authority;
		}

		std::string getPath() {
			return path;
		}

		std::string getCompletedURL() {
			return scheme + authority + path;
		}
};

int main()
{
	std::string newUrl;

	cout << "Please enter a URL: ";
	cin >> newUrl;
	URL u(newUrl);
	cout << "Scheme: " << u.getScheme() << endl;
	cout << "Authority: " << u.getAuthority() << endl;
	cout << "Path: " << u.getPath() << endl;
	cout << "Completed URL: " << u.getCompletedURL() << endl;

	return 0;

}

