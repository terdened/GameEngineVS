//
// Created by terde on 19.02.2017.
//

#ifndef GAME_RESOURCE_H
#define GAME_RESOURCE_H
#include <string>

using namespace std;

namespace GameEngine {
    class Resource {
    private:
        string filename;
        unsigned int handle;
        string name;
        string path;

    public:
        Resource(const unsigned int handle, const string &filename, const string &path, const string &name) :
                handle(handle), filename(filename), path(path), name(name) {}

        string Filename() {
            return filename;
        }

        unsigned int Handle() {
            return handle;
        }

        string Name() {
            return name;
        }

        string Path() {
            return path;
        }
    };
}


#endif //GAME_RESOURCE_H
