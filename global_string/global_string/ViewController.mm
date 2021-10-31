//
//  ViewController.m
//  global_string
//
//  Created by 郑俊明 on 2021/10/31.
//

#import "ViewController.h"

extern void PrintByTeacher();

extern void PrintByStudent();

extern void PrintByCar();


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    PrintByTeacher();
    PrintByStudent();
    PrintByCar();
}


@end
