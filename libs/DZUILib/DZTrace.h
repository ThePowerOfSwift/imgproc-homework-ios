//
//  DZTrace.h
//  DZUILib
//
//  Created by Simon Kim on 12. 6. 26..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#ifndef DZUILib_DZTrace_h
#define DZUILib_DZTrace_h

#define __TRACE_IMETHOD_BEGIN__ NSLog(@"[%@-%@:%d] begin", NSStringFromClass([self class]), NSStringFromSelector(_cmd), __LINE__);
#define __TRACE_IMETHOD_END__ NSLog(@"[%@-%@:%d] end", NSStringFromClass([self class]), NSStringFromSelector(_cmd), __LINE__);


#endif
