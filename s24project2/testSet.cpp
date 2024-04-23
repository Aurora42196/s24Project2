//
//  main.cpp
//  s24Project2
//
//  Created by Cameron Maiden on 4/18/24.
//


///////////////////////////////////////////////////////////////////////////
/// Test cases from yours truly
///////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <cassert>
//#include "Set.h"
//
//using namespace std;
//
//int main()
//{
//    // Test 1: To see if the default constructor and destructor allocate and deallocate as intended
//    Set s;
//    ItemType x = "xxx";
//    assert(s.empty() == true);
//    assert(s.size() == 0);
//    assert(s.contains(x) == false);
//    
//    // Test 2: To see if the insert function works and sorts the items in the list and rejects duplicates
//    Set test2;
//    test2.insert("bat");
//    test2.insert("fox");
//    test2.insert("duck");
//    test2.insert("elephant");
//    test2.insert("gorilla");
//    test2.insert("fox");
//    
//    assert(test2.size() == 5);
////    test2.dump();
//    
//    // Test 3: To test the erase function
//    test2.erase("elephant");
//    assert(test2.size() == 4);
//    assert(test2.erase("elephant") == false);
//    assert(test2.contains("elephant") == false);
//    test2.erase("gorilla");
//    test2.dump();
//    
//
//    
//    
//    cout << "Passed all tests!" << endl;
//}

///////////////////////////////////////////////////////////////////////////
/// Test case to see if all the functions are implemented and compile
///////////////////////////////////////////////////////////////////////////

//#include "Set.h"
//#include <type_traits>
//
//#define CHECKTYPE(c, f, r, a)  \
//{  \
//static_assert(std::is_same<decltype(&c::f), r (c::*)a>::value, \
//"You did not declare " #c "::" #f " as the Project 2 spec does");  \
//auto p = static_cast<r (c::*)a>(&c::f);  \
//(void) p;  \
//}
//#define CHECKTYPENONMEMBER(f, t)  \
//{  \
//static_assert(std::is_same<decltype(f), t>::value, \
//"You did not declare " #f " as the Project 2 spec does");  \
//auto p = static_cast<std::add_pointer<t>::type>(f);  \
//(void) p;  \
//}
//
//static_assert(std::is_default_constructible<Set>::value,
//              "Set must be default-constructible.");
//static_assert(std::is_copy_constructible<Set>::value,
//              "Set must be copy-constructible.");
//static_assert(std::is_copy_assignable<Set>::value,
//              "Set must be assignable.");
//static_assert(std::is_same<decltype(*(Set*)(0) = Set()), Set&>::value,
//              "Set::operator= return type should be Set&");
//
//void thisFunctionWillNeverBeCalled()
//{
//    CHECKTYPE(Set, empty,    bool, () const);
//    CHECKTYPE(Set, size,     int,  () const);
//    CHECKTYPE(Set, insert,   bool, (const ItemType&));
//    CHECKTYPE(Set, erase,    bool, (const ItemType&));
//    CHECKTYPE(Set, contains, bool, (const ItemType&) const);
//    CHECKTYPE(Set, get,      bool, (int, ItemType&) const);
//    CHECKTYPE(Set, swap,     void, (Set&));
//    CHECKTYPENONMEMBER(unite,     void(const Set&, const Set&, Set&));
//    CHECKTYPENONMEMBER(inOnlyOne, void(const Set&, const Set&, Set&));
//}
//
//int main()
//{}

///////////////////////////////////////////////////////////////////////////
/// Test cases from Discord
///////////////////////////////////////////////////////////////////////////

// Credits:
//  TESTNUM 1 - Professor Smallberg
// Description:
//  Preface - Functions such as contains(), size(), and empty()
//            will be periodically tested throughout other test cases.
// ItemType - std::string
//  TESTNUM 1 - Every function is implemented and builds correctly
//  TESTNUM 2 - Default constructor
//  TESTNUM 3 - Insert function
//  TESTNUM 4 - Erase function
//  TESTNUM 5 - Get function
//  TESTNUM 6 - Swap function
//  TESTNUM 7 - Copy constructor
//  TESTNUM 8 - Assignment Operator
//  TESTNUM 9 - Unite function
//  TESTNUM 10 - OnlyInOne function
// ItemType - unsigned long
//  TESTNUM 11 - Different ItemType

#define TESTNUM 5 // Define the test number you want (Comment out or put value not 1-11 to build program normally)

#ifndef TESTNUM
#define TESTUM = 0
#endif

#if TESTNUM == 1 // Tests to make sure every function is implemented and builds correctly
#include "Set.h"
#include <type_traits>
#include <iostream>

#define CHECKTYPE(c, f, r, a)  \
        {  \
         static_assert(std::is_same<decltype(&c::f), r (c::*)a>::value, \
             "You did not declare " #c "::" #f " as the Project 2 spec does");  \
         auto p = static_cast<r (c::*)a>(&c::f);  \
         (void) p;  \
        }
#define CHECKTYPENONMEMBER(f, t)  \
        {  \
         static_assert(std::is_same<decltype(f), t>::value, \
             "You did not declare " #f " as the Project 2 spec does");  \
         auto p = static_cast<std::add_pointer<t>::type>(f);  \
         (void) p;  \
        }


static_assert(std::is_default_constructible<Set>::value,
    "Set must be default-constructible.");
static_assert(std::is_copy_constructible<Set>::value,
    "Set must be copy-constructible.");
static_assert(std::is_copy_assignable<Set>::value,
    "Set must be assignable.");
static_assert(std::is_same<decltype(*(Set*)(0) = Set()), Set&>::value,
    "Set::operator= return type should be Set&");

void thisFunctionWillNeverBeCalled()
{
    CHECKTYPE(Set, empty, bool, () const);
    CHECKTYPE(Set, size, int, () const);
    CHECKTYPE(Set, insert, bool, (const ItemType&));
    CHECKTYPE(Set, erase, bool, (const ItemType&));
    CHECKTYPE(Set, contains, bool, (const ItemType&) const);
    CHECKTYPE(Set, get, bool, (int, ItemType&) const);
    CHECKTYPE(Set, swap, void, (Set&));
    CHECKTYPENONMEMBER(unite, void(const Set&, const Set&, Set&));
    CHECKTYPENONMEMBER(inOnlyOne, void(const Set&, const Set&, Set&));
}

int main()
{
    std::cout << "Test Passed." << std::endl;
}

#elif TESTNUM == 2 // Tests default constructor
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test2;
    assert(test2.size() == 0); // Ensures set size is 0
    assert(test2.empty()); // Ensures empty function works
    assert(!test2.contains("")); // Ensures set has no "default" value
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 3 // Tests insert function
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test3;
    test3.insert("Apple");
    test3.insert("Carrot");
    assert(!test3.insert("Apple")); // Tests duplicate prevention and correct bool return
    test3.insert("Banana");
    assert(test3.insert("")); // Ensures empty string behaves correctly and correct bool return
    assert(test3.size() == 4); // Ensures size is correctly updated
    assert(test3.contains("Apple") && test3.contains("Banana") && test3.contains("Carrot") && test3.contains(""));
    test3.dump();
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 4 // Tests erase function
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test4;
    test4.insert("Apple");
    test4.insert("Banana");
    test4.insert("");
    assert(test4.erase("")); // Tests erase for item in set and ensures correct bool return
    assert(test4.size() == 2); // Ensures size is correctly updated
    assert(test4.contains("Apple") && test4.contains("Banana") && !test4.contains("")); // Verify set is updated
    assert(!test4.erase("")); // Tests erase for item not in set and ensures correct bool return
    assert(test4.size() == 2); // Ensures size is unchanged
    assert(test4.contains("Apple") && test4.contains("Banana") && !test4.contains("")); // Ensures set is unchanged
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 5 // Tests get function
#include "Set.h"
#include <cassert>
#include <iostream>
#include <string>

int main()
{
    Set test5;
    test5.insert("Apple");
    test5.insert("Banana");
    test5.insert("Carrot");
    std::string value;
    assert(test5.get(0, value)); // Tests correct bool return
    assert(value == "Carrot");                        // Ensures get function follows correct behavior
    assert(test5.get(1, value) && value == "Banana"); // ^
    assert(test5.get(2, value) && value == "Apple");  // ^
    assert(!test5.get(-1, value) && value == "Apple"); // Tests correct bool return and behavior for negative parameter
    assert(!test5.get(3, value) && value == "Apple"); // Tests correct bool return and behavior for unmet condition
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 6 // Tests swap function
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test6a;
    test6a.insert("Apple");
    test6a.insert("Banana");
    test6a.insert("Carrot");
    Set test6b;
    test6b.insert("Deer");
    test6b.insert("Elephant");
    test6a.swap(test6b); // Swaps two non-empty sets
    assert(test6a.size() == 2); // Verifies size of a
    assert(test6a.contains("Deer") && test6a.contains("Elephant")); // Verifies content of a
    assert(test6b.size() == 3); // Verifies size of b
    assert(test6b.contains("Apple") && test6b.contains("Banana") && test6b.contains("Carrot")); // Verifies content of b
    Set test6c;
    test6a.swap(test6c); // Swaps one non-empty set and one empty set and proceeds to verify sizes and content
    assert(test6a.empty());
    assert(!test6a.contains("Deer") && !test6a.contains("Elephant"));
    assert(test6c.size() == 2);
    assert(test6c.contains("Deer") && test6c.contains("Elephant"));
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 7 // Tests copy constructor
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test7a;
    test7a.insert("Apple");
    test7a.insert("Banana");
    test7a.insert("Carrot");
    Set test7b(test7a); // Envokes copy constructor
    assert(test7a.size() == 3); // Ensure original set is unchanged
    assert(test7a.contains("Apple") && test7a.contains("Banana") && test7a.contains("Carrot"));
    assert(test7b.size() == 3); // Ensure copy is identical
    assert(test7b.contains("Apple") && test7b.contains("Banana") && test7b.contains("Carrot"));
    test7b.erase("Apple"); // Erase item from copy only
    assert(test7a.contains("Apple") && !test7b.contains("Apple")); // Ensure aliasing has not occurred
    Set test7c; // Same test but for empty sets
    Set test7d(test7c);
    assert(test7c.empty() && test7d.empty());
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 8 // Tests assignment operator
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test8a;
    test8a.insert("Apple");
    test8a.insert("Banana");
    Set test8b;
    test8b = test8a; // Envoke assignment (empty = non-empty)
    assert(test8a.size() == 2); // Ensure original set is unchanged
    assert(test8a.contains("Apple") && test8a.contains("Banana"));
    assert(test8b.size() == 2); // Ensure new set is identical
    assert(test8b.contains("Apple") && test8b.contains("Banana"));
    test8b.erase("Apple"); // Erase item from copy only
    assert(test8a.contains("Apple") && !test8b.contains("Apple")); // Ensure aliasing has not occurred
    test8a = test8b; // Envoke assignment (non-empty = smaller non-empty)
    assert(test8b.size() == 1); // Ensure original set is unchanged
    assert(test8b.contains("Banana"));
    assert(test8a.size() == 1); // Ensure new set is identical
    assert(!test8a.contains("Apple") && test8a.contains("Banana")); // Make sure extra item in new set was deleted
    Set test8c;
    test8a = test8c; // Envoke assignment (non-empty = empty)
    assert(test8a.empty() && test8c.empty());
    assert(!test8a.contains("Banana") && !test8c.contains("Banana"));
    test8a.insert("Apple");
    assert(test8a.contains("Apple") && !test8c.contains("Apple")); // Test for aliasing again
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 9 // Tests unite function
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test9a;
    test9a.insert("Apple");
    test9a.insert("Banana");
    test9a.insert("Carrot");
    Set test9b;
    test9b.insert("Apple");
    test9b.insert("Deer");
    test9b.insert("Elephant");
    Set test9c;
    unite(test9a, test9b, test9c); // Envoke unite with empty result set
    assert(test9c.size() == 5);
    assert(test9c.contains("Apple") && test9c.contains("Banana") && test9c.contains("Carrot"));
    assert(test9c.contains("Deer") && test9c.contains("Elephant"));
    test9b.insert("Fox");
    unite(test9a, test9b, test9c); // Envoke unite with non-empty result set
    assert(test9c.size() == 6);
    assert(test9c.contains("Apple") && test9c.contains("Banana") && test9c.contains("Carrot"));
    assert(test9c.contains("Deer") && test9c.contains("Elephant") && test9c.contains("Fox"));
    unite(test9a, test9b, test9a); // Envoke unite with aliasing
    assert(test9a.size() == 6);
    assert(test9a.contains("Apple") && test9a.contains("Banana") && test9a.contains("Carrot"));
    assert(test9a.contains("Deer") && test9a.contains("Elephant") && test9a.contains("Fox"));
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 10 // Tests inOnlyOne function
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test10a;
    test10a.insert("Apple");
    test10a.insert("Banana");
    test10a.insert("Carrot");
    Set test10b;
    test10b.insert("Apple");
    test10b.insert("Banana");
    test10b.insert("Elephant");
    Set test10c;
    inOnlyOne(test10a, test10b, test10c); // Envoke inOnlyOne with empty result set
    assert(test10c.size() == 2);
    assert(test10c.contains("Carrot") && test10c.contains("Elephant"));
    assert(!test10c.contains("Apple") && !test10c.contains("Banana"));
    test10b.insert("Fox");
    inOnlyOne(test10a, test10b, test10c); // Envoke inOnlyOne with non-empty result set
    assert(test10c.size() == 3);
    assert(test10c.contains("Carrot") && test10c.contains("Elephant") && test10c.contains("Fox"));
    assert(!test10c.contains("Apple") && !test10c.contains("Banana"));
    inOnlyOne(test10a, test10b, test10a); // Envoke inOnlyOne with aliasing
    assert(test10a.size() == 3);
    assert(test10a.contains("Carrot") && test10a.contains("Elephant") && test10a.contains("Fox"));
    assert(!test10a.contains("Apple") && !test10a.contains("Banana"));
    std::cout << "Test passed." << std::endl;
}
#elif TESTNUM == 11 // Tests with different ItemType
#include "Set.h"
#include <cassert>
#include <iostream>

int main()
{
    Set test11a;
    assert(test11a.size() == 0 && test11a.empty());
    assert(test11a.insert(1) && test11a.insert(2) && test11a.insert(3) && !test11a.insert(1));
    assert(test11a.contains(1) && !test11a.contains(0));
    Set test11b(test11a);
    assert(test11b.erase(1) && test11b.size() == 2 && !test11b.erase(0));
    test11b = test11a;
    assert(test11a.size() == 3 and test11b.size() == 3);
    unsigned long x;
    assert(test11a.get(0, x) && x == 3 && !test11a.get(-1,x));
    test11b.erase(x);
    test11a.swap(test11b);
    assert(test11a.size() == 2 && test11b.size() == 3);
    Set test11c;
    unite(test11a, test11b, test11c);
    assert(test11c.size() == 3);
    test11c.insert(4);
    unite(test11a, test11b, test11c);
    assert(test11c.size() == 3);
    unite(test11a, test11b, test11a);
    assert(test11a.size() == 3);
    test11b.insert(10);
    test11b.insert(11);
    Set test11d;
    inOnlyOne(test11a, test11b, test11d);
    assert(test11d.size() == 2);
    test11b.insert(12);
    inOnlyOne(test11a, test11b, test11d);
    assert(test11d.size() == 3);
    inOnlyOne(test11a, test11b, test11a);
    assert(test11a.size() == 3);
    std::cout << "Test passed." << std::endl;
}
#else
#include "Set.h"
#include <iostream>
int main() { std::cout << "Set class compiled. No test case selected." << std::endl; }

#endif
