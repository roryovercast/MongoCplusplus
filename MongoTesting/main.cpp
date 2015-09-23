//
//  main.cpp
//  MongoTesting
//
//  Created by Rory Overcast on 9/22/15.
//  Copyright (c) 2015 Rory Overcast. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h" // for the driver

void run() {
    mongo::DBClientConnection c;
    c.connect("localhost:3001");
    
    for (int count=0; count<50; count++) {
        std::cout << count << std::endl;
        
        c.update("meteor.todos",
                 BSON("_id" << "gToXqZYDNdKuAMXpz"),
                 BSON("$set" << BSON( "text" << count))
                 );
        usleep(100000);
    }
}

int main() {
    mongo::client::initialize();
    try {
        run();
        std::cout << "connected ok" << std::endl;
    } catch( const mongo::DBException &e ) {
        std::cout << "caught " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}