#include <iostream>
#include <vector>
#include <list>

void Swap(std::list<int>& to, std::list<int>& from) {
	to.push_front(from.front()); // Extracts disk from first rod
	from.pop_front(); // Insert to second
}

void rec_swap(std::list<int>& cur, std::list<int>& tar, std::list<int>& buf, std::size_t size) {

	if (size == 1) {
		Swap(tar, cur);
		return;
	} // Case when count of disks on a rod is 1.

	rec_swap(cur, buf, tar, size - 1); // Recursively move disks to the buffer except for the lower one

	Swap(tar, cur); // Move the lower disk to the target rod

	rec_swap(buf, tar, cur, size - 1); // Recursively move disks from the buffer to the target
}

int main()
{
	std::vector<std::list<int>> stacks(3); // count of rods
	// Puzzle can be solved with stack, but function Swap work faster with list.

	{
		std::list<int> tmp;

		for (int i = 8; i > 0; tmp.push_front(i--));

		stacks[0] = tmp;
	} // Fills first rod

	int num = 0;
	for (auto stack : stacks) {
		std::cout << num++ << ": ";
		while (stack.size() > 0) {
			std::cout << stack.front();
			stack.pop_front();
		}
		std::cout << '\n';
	} // Shows content of rods

	rec_swap(stacks[0], stacks[1], stacks[2], 8); // Calls the function to use solve puzzle
	// first argument is current rod, where will extracts disks.
	// Second argument is target rod, where will inserts disks.
	// Third argument is buffer rod, which will storage disks

	num = 0;
	for (auto stack : stacks) {
		std::cout << num++ << ": ";
		while (stack.size() > 0) {
			std::cout << stack.front();
			stack.pop_front();
		}
		std::cout << '\n';
	} // Shows content of rods again
}