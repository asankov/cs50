//
//  NoteViewController.swift
//  Notes
//
//  Created by Anton Sankov on 5/24/20.
//  Copyright © 2020 Anton Sankov. All rights reserved.
//

import UIKit

class NoteViewController: UIViewController {
    var note: Note!
    
    @IBOutlet var textView: UITextView!
    
    override func viewDidLoad() {
        textView.text = note.contents
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        note.contents = textView.text
        NoteManager.default.saveNote(note: note)
    }
}

