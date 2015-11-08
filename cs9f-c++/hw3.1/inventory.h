#include <vector>
#include <string>
// #include <utility>
#include <map>

using namespace std;
typedef pair<string, int> Entry;

class Inventory {
	public:
		Inventory ();
		void Update (string item, int amount);
		void ListByName ();
		void ListByQuantity ();
	private:
		// You provide this.
		map<string, int> table;
};
