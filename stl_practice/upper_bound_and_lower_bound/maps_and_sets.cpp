// # Sets
// The time complexity of lower_bound() for sets is O(n), where n is the number
// of elements present in the set...
// Since sets store their elements in sorted order, the time complexity of lower_bound / upper_bound should
// be O(logn) not O(n)... To get O(logn) time complexity use s.upper_bound() / s.lower_bounder (s is a set, upper_bound and lower_bound
// are its member functions), instead of upper_bound and lower_bound...
//
// # Maps
// upper_bound and lower_bound operate on the keys of the map not the values...
// use m.upper_bound / m.lower_bound instead of upper_bound / lower_bound to get O(logn) time
// complexity.
