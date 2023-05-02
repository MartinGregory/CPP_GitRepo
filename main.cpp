//  Neural_Network_FeedForward
//
//  Created by Martin Gregory Sendrowicz on 4/26/23.
//

#include "Perceptron.hpp"
#include "MultiLayerPerceptron.hpp"
#include "Globals.hpp"
#include "Activation_Function.hpp"
#include <iostream>

//....................................................................................................
/* In this test we are running the Perceptron model to simulate Logic AND Gate. There are only two
dimensions X and Y which represent points (0,0), (0,1), (1,0) and (1,1). These points are linearly
separable and are on a 2D Cartesian Plane. These points represent the values of the AND Table:
    0 and 0 = 0     input( 0,0 )
    0 and 1 = 0     input( 0,1 )
    1 and 0 = 0     input( 1,0 )
    1 and 1 = 1     input( 1,1 )
The task for the Perceptron model is to find the decision boundry that correctly seperates/classifies
the input are either 0 (false) or 1 (true). Note that since this data is linearly separable all we
need is a single Perceptron -- hence our Neural Network will only have one node.
*/
void test0(){
    
    Perceptron * p {nullptr} ;
    p = new Perceptron( 2 ) ;           // for Logic AND gate input size is 2
    if( p == nullptr )
        return ;
    
    (*p).set_weights( {10,10,-15} ) ;   // these weights are NOT learned by the network (just testing)
    
    Activation_Function f ;
    
    std::cout << "AND GATE:\n" ;
    std::cout <<"0 AND 0 : "<< ((f.sigmoid( (*p).run( {0,0} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"0 AND 1 : "<< ((f.sigmoid( (*p).run( {0,1} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"1 AND 0 : "<< ((f.sigmoid( (*p).run( {1,0} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"1 AND 1 : "<< ((f.sigmoid( (*p).run( {1,1} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    
    delete p ;
}
//....................................................................................................
/* In this test we are running the Perceptron model to simulate Logic OR Gate. There are only two
dimensions X and Y which represent points (0,0), (0,1), (1,0) and (1,1). These points are linearly
separable and are on a 2D Cartesian Plane. These points represent the values of the OR Table:
    0 and 0 = 0     input( 0,0 )
    0 and 1 = 1     input( 0,1 )
    1 and 0 = 1     input( 1,0 )
    1 and 1 = 1     input( 1,1 )
The task for the Perceptron model is to find the decision boundry that correctly seperates/classifies
the input are either 0 (false) or 1 (true). Note that since this data is linearly separable all we
need is a single Perceptron -- hence our Neural Network will only have one node.
*/
void test1(){
    
    Perceptron * p  {nullptr} ;
    p = new Perceptron( 2 ) ;           // for Logic OR gate input size is 2
    if( p == nullptr )
        return ;
    
    (*p).set_weights( {15,15,-10} ) ;   // these weights are NOT learned by the network (just testing)
    
    Activation_Function f ;
    
    std::cout << "OR GATE:\n" ;
    std::cout <<"0 OR 0 : "<< ((f.sigmoid( (*p).run( {0,0} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"0 OR 1 : "<< ((f.sigmoid( (*p).run( {0,1} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"1 OR 0 : "<< ((f.sigmoid( (*p).run( {1,0} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"1 OR 1 : "<< ((f.sigmoid( (*p).run( {1,1} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    
    delete p ;
}
//....................................................................................................
/* In this test we are running the Perceptron model to simulate Logic NAND Gate. There are only two
dimensions X and Y which represent points (0,0), (0,1), (1,0) and (1,1). These points are linearly
separable and are on a 2D Cartesian Plane. These points represent the values of the NAND Table:
    0 and 0 = 1     input( 0,0 )
    0 and 1 = 1     input( 0,1 )
    1 and 0 = 1     input( 1,0 )
    1 and 1 = 0     input( 1,1 )
The task for the Perceptron model is to find the decision boundry that correctly seperates/classifies
the input are either 0 (false) or 1 (true). Note that since this data is linearly separable all we
need is a single Perceptron -- hence our Neural Network will only have one node.
*/
void test2(){
    
    Perceptron * p  {nullptr} ;
    p = new Perceptron( 2 ) ;           // for Logic NAND gate input size is 2
    if( p == nullptr )
        return ;
    
    (*p).set_weights( {-10,-10,15} ) ;   // these weights are NOT learned by the network (just testing)
    
    Activation_Function f ;
    
    std::cout << "NAND GATE:\n" ;
    std::cout <<"0 NAND 0 : "<< ((f.sigmoid( (*p).run( {0,0} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"0 NAND 1 : "<< ((f.sigmoid( (*p).run( {0,1} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"1 NAND 0 : "<< ((f.sigmoid( (*p).run( {1,0} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    std::cout <<"1 NAND 1 : "<< ((f.sigmoid( (*p).run( {1,1} ))) > 0.5 ? 1 : 0 ) << std::endl ;
    
    delete p ;
}
//....................................................................................................
void test3(){
    
    MultiLayerPerceptron net = MultiLayerPerceptron( {2,2,1} ) ;
    //                   NAND Gate       OR Gate      AND Gate
    net.set_weights( { {{-10,-10,15},{15,15,-10}} , {{10,10,-15}} } ) ;
    
    net.print_weights() ;
    
    std::cout << "XOR GATE:\n" ;
    std::cout <<"0 XOR 0 : "<< (((net.run( {0,0} )[0]) > 0.5) ? 1 : 0) << std::endl ;
    std::cout <<"0 XOR 1 : "<< (((net.run( {0,1} )[0]) > 0.5) ? 1 : 0) << std::endl ;
    std::cout <<"1 XOR 0 : "<< (((net.run( {1,0} )[0]) > 0.5) ? 1 : 0) << std::endl ;
    std::cout <<"1 XOR 1 : "<< (((net.run( {1,1} )[0]) > 0.5) ? 1 : 0) << std::endl ;
}
//....................................................................................................
int main() {
    
    srand( u_int( time(NULL) ) ) ; // srand() uses the current time as seed for random generator rand()
    rand() ;
    
//    test0() ;
//    test1() ;
//    test2() ;
    /* If you noticed the pattern, while implementing AND, OR and NAND gates ALL we changed were the
    weights */
    test3() ;
    
    return 0 ;
}//...................................................................................................



