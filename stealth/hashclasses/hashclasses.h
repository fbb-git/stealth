#ifndef _INCLUDED_HASHCLASSES_H_
#define _INCLUDED_HASHCLASSES_H_

#ifndef _INCLUDED_STRING_
#include <string>
#define _INCLUDED_STRING_
#endif

#ifndef _INCLUDED_CCTYPE_
#include <cctype>
#define _INCLUDED_CCTYPE_
#endif

#ifndef _INCLUDED_HASH_MAP_
#define __gnu_cxx   std
#include <ext/hash_map>
#define _INCLUDED_HASH_MAP_
#endif

#ifndef _INCLUDED_ALGORITHM_
#include <algorithm>
#define _INCLUDED_ALGORITHM_
#endif

#ifndef _INCLUDED_MEMORY_
#include <memory>
#define _INCLUDED_MEMORY_
#endif



/*
    This file is copyright (c) GPL, 2001, 2002
    ==========================================
    
    2002/04/10

    april 2002: namespace FBB introduced
                abbreviated class templates defined, 
                char * problems with raw hash_maps are prevented when
                these abbreviations are used.
                With the abbreviations: A default initial size of 100 elements
                is used. The constructor expecting two iterators is available
                as well.

                See the END of this comment section for examples of how 
                to use these abbreviations. 

    jan 2002:   redundant include guards added, 
                required header files adapted,
                for_each() rather than transform() used

    With hash_maps using char const * for the keys:
                         ============

    * Use `HashCharPtr' as 3rd template argument for case-sensitive keys
    * Use `HashCaseCharPtr' as 3rd template argument for case-insensitive 
      keys
    
    * Use `EqualCharPtr' as 4th template argument for case-sensitive keys
    * Use `EqualCaseCharPtr' as 4th template argument for case-insensitive
      keys


    With hash_maps using std::string for the keys:
                         ===========

    * Use `HashString' as 3rd template argument for case-sensitive keys
    * Use `HashCaseString' as 3rd template argument for case-insensitive keys
        
    * OMIT the 4th template argument for case-sensitive keys
    * Use `EqualCaseString' as 4th template argument for case-insensitive 
        keys


    Examples, using int as the value type. Any other type can be used instead
              for the value type:

                                    // key is char const *, case sensitive
        std::hash_map<char const *, int, FBB::HashCharPtr, FBB::EqualCharPtr >
            hashtab;

                                    // key is char const *, case insensitive
        std::hash_map<char const *, int, FBB::HashCaseCharPtr, 
                                         FBB::EqualCaseCharPtr >
            hashtab;

                                    // key is std::string, case sensitive
        std::hash_map<std::string, int, FBB::HashString>
            hashtab;

                                    // key is std::string, case insensitive
        std::hash_map<std::string, int, FBB::HashCaseString, 
                                        FBB::EqualCaseString>
            hashtab;

    Note that with `char const *' keys, the addresses of the char const *'s
    are stored in the hashtable. If the contents of these locations change,
    then the hashtable will produce unexpected results. Therefore, one should
    be VERY careful when using hashtables with raw char * variables, 

    Instead of the above raw typedeclarations, the following shortcuts should
    work as well. Here the char * keys are internally converted to
    auto_ptr<char>, so that the hashtable now contains its own key strings.

        FBB::CharPtrHash<int>       // key is char const *, case sensitive
            hashtab;
                                    
        FBB::CharCasePtrHash<int>   // key is char const *, case insensitive
            hashtab;
                                    
        FBB::StringHash<int>        // key is std::string, case sensitive
            hashtab;

        FBB::StringCaseHash<int>    // key is std::string, case insensitive
            hashtab;

    With these template types iterators and other map-members are also
    available. E.g.,

    --------------------------------------------------------------------------
    extern FBB::StringHash<int> dh;

    for (FBB::StringHash<int>::iterator it = dh.begin(); it != dh.end(); it++)
        std::cout << it->first << " - " << it->second << std::endl;
    --------------------------------------------------------------------------

    Feb. 2001 - April 2002
    Frank B. Brokken (f.b.brokken@rc.rug.nl)
*/

namespace FBB
{

class _charptr: public std::auto_ptr<char>
{
    public:
        _charptr(char const *cp)
        :
            std::auto_ptr<char>
            (
                cp ? 
                    strcpy(new char[strlen(cp + 1)], cp)
                :
                    strcpy(new char[1], "")
            )
        {}
        operator char const *() const
        {
            return this->get();
        }
};

        
class _casecharptr: public _charptr
{
    public:
        _casecharptr(char const *cp)
        :
            _charptr(cp)
        {
            for (char *cp = this->get(); *cp; cp++)
                *cp = tolower(*cp);
        }
};

        
class HashCharPtr
{
    public: 
        unsigned operator()(char const *str) const
        { 
            return std::hash<char const *>()(str);
        }
};

class EqualCharPtr
{
    public: 
        bool operator()(char const *x, char const *y) const 
        { 
            return !strcmp(x, y); 
        }
};

class HashCaseCharPtr
{
    public: 
        unsigned operator()(char const *str) const
        { 
            std::string s = str;
            for_each(s.begin(), s.end(), *this);
            return std::hash<char const *>()(s.c_str());
        }
        void operator()(char &c) const
        {
            c = tolower(c);
        }
};

class EqualCaseCharPtr
{
    public: 
        bool operator()(char const *x, char const *y) const 
        { 
            return !strcasecmp(x, y); 
        }
};

class HashString
{
    public: 
        unsigned operator()(std::string const &str) const
        { 
            return std::hash<char const *>()(str.c_str());
        }
};

class HashCaseString: public HashCaseCharPtr
{
    public: 
        unsigned operator()(std::string const &str) const
        { 
            return HashCaseCharPtr::operator()(str.c_str());
        }
};

class EqualCaseString
{
    public: 
        bool operator()(std::string const &s1, std::string const &s2) const 
        { 
            return !strcasecmp(s1.c_str(), s2.c_str()); 
        }
};

template<typename Value>
class CharPtrHash: public 
    std::hash_map<_charptr, Value, HashCharPtr, EqualCharPtr >
{
    public:
        CharPtrHash(unsigned size = 100)
        :
            std::hash_map
            <_charptr, Value, HashCharPtr, EqualCharPtr >(size)
        {}
        template <typename InputIterator>
        CharPtrHash(InputIterator first, InputIterator beyond)
        :
            std::hash_map<_charptr, Value, HashCharPtr, EqualCharPtr>
                         (first, beyond)
        {}
};


template<typename Value>
class CharCasePtrHash: public 
    std::hash_map<_casecharptr, Value, HashCharPtr, EqualCharPtr >
{
    public:
        CharCasePtrHash(unsigned size = 100)
        :
            std::hash_map
            <_casecharptr, Value, HashCharPtr, EqualCharPtr >(size)
        {}
        template <typename InputIterator>
        CharCasePtrHash(InputIterator first, InputIterator beyond)
        :
            std::hash_map<_casecharptr, Value, 
                            HashCharPtr, EqualCharPtr>(first, beyond)
        {}
};

template<typename Value>
class StringHash: public std::hash_map<std::string, Value, HashString>
{
    public:
        StringHash(unsigned size = 100)
        :
            std::hash_map
            <std::string, Value, HashString>(size)
        {}
        template <typename InputIterator>
        StringHash(InputIterator first, InputIterator beyond)
        :
            std::hash_map<std::string, Value, HashString>
                         (first, beyond)
        {}
};


template<typename Value>
class StringCaseHash: public 
        std::hash_map<std::string, Value, HashCaseString, EqualCaseString>
{
    public:
        StringCaseHash(unsigned size = 100)
        :
            std::hash_map
            <std::string, Value, HashCaseString, EqualCaseString>(size)
        {}
        template <typename InputIterator>
        StringCaseHash(InputIterator first, InputIterator beyond)
        :
            std::hash_map<std::string, Value, HashCaseString, EqualCaseString>
                         (first, beyond)
        {}
};


}
#endif



