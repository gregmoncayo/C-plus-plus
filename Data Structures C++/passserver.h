//
//  passserver.hpp
//  proj5
//
//  Created by Gregory Moncayo on 4/21/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//

#ifndef passserver_h
#define passserver_h
#include "hashtable.h"

namespace cop4530
{
    class PassServer : public HashTable<string, string>
    {
        public:
            PassServer(size_t size = 101);
            ~PassServer();
            bool load(const char *filename);
            bool addUser(std::pair<string,  string> & kv);
            bool addUser(std::pair<string, string> && kv);
            bool removeUser(const string & k);
            bool changePassword(const pair<string, string> &p, const string & newpassword);
            bool find(const string & user) const;
            void dump();
            size_t size() const;
            bool write_to_file(const char *filename) const;
        
        private:
            string encrypt(const string & str);
    };
}
#endif
 /* passserver_hpp */
