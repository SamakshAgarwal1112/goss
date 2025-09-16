#include <bits/stdc++.h>

using namespace std;

int main() {

    string arr[200] = {
        "algorithm", "array", "variable", "function", "class",
        "object", "inheritance", "polymorphism", "encapsulation", "abstraction",
        "constructor", "destructor", "template", "namespace", "operator",
        "pointer", "reference", "stack", "queue", "linkedlist",
        "recursion", "iteration", "loop", "conditional", "exception",
        "thread", "process", "concurrency", "synchronization", "mutex",
        "semaphore", "lock", "deadlock", "racecondition", "debugging",
        "compiler", "interpreter", "assembler", "bytecode", "virtualmachine",
        "binary", "hexadecimal", "octal", "decimal", "bitwise",
        "shift", "andoperator", "oroperator", "xoroperator", "notoperator",
        "boolean", "integer", "float", "double", "char",
        "string", "struct", "union", "enum", "typedef",
        "static", "const", "volatile", "extern", "inline",
        "virtual", "override", "abstract", "interface", "lambda",
        "closure", "callback", "event", "signal", "slot",
        "delegate", "generic", "overloading", "overriding", "casting",
        "upcasting", "downcasting", "dynamic", "staticbinding", "latebinding",
        "earlybinding", "compiletime", "runtime", "jitcompiler", "intermediatecode",
        "optimization", "profiling", "benchmarking", "performance", "scalability",
        "latency", "throughput", "parallelism", "vectorization", "pipeline",
        "cache", "register", "heap", "stackframe", "memoryleak",
        "garbagecollection", "referencecounting", "smartpointer", "weakpointer", "uniquepointer",
        "sharedpointer", "danglingpointer", "segmentationfault", "bufferoverflow", "stackoverflow",
        "underoverflow", "nullpointer", "dereference", "address", "offset",
        "index", "iterator", "range", "slice", "substring",
        "token", "lexer", "parser", "syntax", "semantics",
        "grammar", "ast", "byte", "opcode", "instruction",
        "mnemonic", "registerallocation", "linker", "loader", "symboltable",
        "relocation", "dynamiclinking", "staticlinking", "library", "framework",
        "sdk", "api", "endpoint", "protocol", "http",
        "https", "tcp", "udp", "socket", "port",
        "firewall", "encryption", "hashing", "checksum", "digest",
        "sha256", "md5", "rsa", "aes", "des",
        "certificate", "ssl", "tls", "handshake", "nonce",
        "salt", "keyexchange", "authentication", "authorization", "tokenization",
        "oauth", "jwt", "session", "cookie", "cachecontrol",
        "rest", "graphql", "soap", "websocket", "microservice",
        "container", "docker", "kubernetes", "orchestration", "scaling",
        "replica", "cluster", "node", "pod", "deployment",
        "ci", "cd", "pipelinebuild", "integration", "unitest",
    };

    ofstream myfile("sample.txt");
    if (!myfile.is_open()) {
        cerr << "Error opening file!\n";
        return 1;
    }

    string str;
    for(int i=0; i<10000000; i++){
        int index = rand() % 200;
        int newline = rand() % 5;
        str += arr[index];
        if(newline%5) str+=" ";
        else {
            myfile << str << "\n";
            str.clear();
        }
    }
    if (!str.empty()) {
        myfile << str << "\n";
    }
    myfile.close();
    return 0;
}