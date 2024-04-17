//
//  Queue.swift
//  BOJ
//
//  Created by J213h on 4/4/24.
//

import Foundation

protocol Queueable {
    associatedtype Element
    mutating func enqueue(_ newElement: Element)
    mutating func dequeue() -> Element?
    mutating func count() -> Int
}

struct DSQueue<Element>: Queueable {
    var inStack = [Element]()
    var outStack = [Element]()
    
    mutating func enqueue(_ newElement: Element) {
        inStack.append(newElement)
    }
    
    mutating func dequeue() -> Element? {
        if outStack.isEmpty {
            outStack = inStack.reversed()
            inStack.removeAll()
        }
        
        return outStack.popLast()
    }
    
    mutating func count() -> Int {
        return inStack.count + outStack.count
    }
}
