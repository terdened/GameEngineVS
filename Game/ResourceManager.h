//
// Created by terde on 19.02.2017.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include "Resource.h"
#include "FontResource.h"

using namespace std;

namespace GameEngine {
    class ResourceManager {
    private:
        void (*createResource)(Resource **, const unsigned int, const string &, const string &);

        stack<unsigned int> handles;
        map<string, shared_ptr<Resource>> resources;
    public:
        ResourceManager(void (*createResource)(Resource **, const unsigned int, const string &, const string &))
                : createResource(createResource) {}

        template<class TResource>
        unsigned int Add(const string &filename, const string &name, const string &path = "./") {
            unsigned int handle = 1;
            if (handles.size() > 0)
                handle = handles.top() + 1;

            shared_ptr<TResource> newResource(new TResource(handle, filename, path, name));
            resources[name] = newResource;
            handles.push(handle);

			return handle;
        }

        template<class TResource>
        shared_ptr<TResource> GetElement(const string &name) {
            auto element = resources[name];
            return std::static_pointer_cast<TResource> (element);
        }

        map<string, shared_ptr<Resource>> Resources() {
            return resources;
        };

        void Remove(const unsigned int handle);

        void EmptyList();
    };
}


#endif //GAME_RESOURCEMANAGER_H
