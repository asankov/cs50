//
//  ViewController.swift
//  Notes
//
//  Created by Anton Sankov on 5/24/20.
//  Copyright © 2020 Anton Sankov. All rights reserved.
//

import UIKit

class ViewController: UITableViewController {
    var notes: [Note] = []

    @IBAction func addNote() {
        let _ = NoteManager.default.createNote()
        reload()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        reload()
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return notes.count
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            let deleted = NoteManager.default.deleteNoteWith(id: notes[indexPath.row].id)
            if deleted {
                notes.remove(at: indexPath.row)
                tableView.deleteRows(at: [indexPath], with: .fade)
            }
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "NoteCell", for: indexPath)
        cell.textLabel?.text = notes[indexPath.row].contents
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "NoteSegue" {
            if let destination = segue.destination as? NoteViewController {
                destination.note = notes[self.tableView.indexPathForSelectedRow!.row]
            }
        }
    }
    
    func reload() {
        notes = NoteManager.default.getAllNotes()
        self.tableView.reloadData()
    }
}
