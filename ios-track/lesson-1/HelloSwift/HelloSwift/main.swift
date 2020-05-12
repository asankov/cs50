//
//  main.swift
//  HelloSwift
//
//  Created by Anton Sankov on 5/13/20.
//  Copyright © 2020 Anton Sankov. All rights reserved.
//

import Foundation

class Track {
    let name: String
    let instructor: String
    
    init(name: String, instructor: String) {
        self.name = name
        self.instructor = instructor
    }
}

let tracks = [
    Track(name: "Mobile", instructor: "Tommy"),
    Track(name: "Games", instructor: "Colton"),
    Track(name: "Web", instructor: "Brian")
]

let students = ["Harry", "Ron", "Hermione"]
var assignments: [String : Track] = [:]

for student in students {
    let index = Int.random(in: 0 ..< tracks.count)
    assignments[student] = tracks[index]
}

for (student, track) in assignments {
    print("\(student) got \(track.name) with \(track.instructor)")
}

