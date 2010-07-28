#include "OperationRepositoryPartFused.hpp"

using namespace std;
using namespace RTT;
using namespace RTT::detail;


string OperationRepositoryPartHelper::description(OperationBase* op) {
    return op->getDescriptions().front();
}

vector<interface::ArgumentDescription> OperationRepositoryPartHelper::getArgumentList(OperationBase* op, const int arity, const vector<string>& arg_types ) {
    vector<string> descr = op->getDescriptions();
    vector<interface::ArgumentDescription> ret;
    // resize for undocumented arguments.
    descr.resize( 1 + arity * 2 );

    for ( int i=0; i < arity; i++ )
        ret.push_back(interface::ArgumentDescription(descr[i*2+1],descr[i*2+2], arg_types[i] ));

    return ret;
}
