//
//  main.m
//  Undecimus
//
//  Created by pwn20wnd on 8/29/18.
//  Copyright © 2018 - 2019 Pwn20wnd. All rights reserved.
//

#include <dlfcn.h>
#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#include <common.h>

int main(int argc, char * argv[]) {
    init_function();
    signal(SIGPIPE, SIG_IGN);
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
