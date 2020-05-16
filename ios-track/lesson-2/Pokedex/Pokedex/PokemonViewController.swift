//
//  PokemonViewController.swift
//  Pokedex
//
//  Created by Anton Sankov on 5/14/20.
//  Copyright © 2020 Anton Sankov. All rights reserved.
//

import UIKit

class PokemonViewController: UIViewController {
    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var numberLabel: UILabel!
    @IBOutlet var type1Label: UILabel!
    @IBOutlet var type2Label: UILabel!
    @IBOutlet var catchButton: UIButton!
    var pokemon: Pokemon!
    var pokemonCaught: Bool = false

    override func viewDidLoad() {
        super.viewDidLoad()
        
        type1Label.text = ""
        type2Label.text = ""
        pokemonCaught = UserDefaults.standard.bool(forKey: pokemon.name)
        setTitle()
        
        let url = URL(string: pokemon.url)
        guard let u = url else {
            return
        }
        
        URLSession.shared.dataTask(with: u, completionHandler:  { (data, response, error) in
            guard let data = data else {
                return
            }
            
            do {
                let pokemonData = try JSONDecoder().decode(PokemonData.self, from: data)
                
                DispatchQueue.main.async {
                    self.nameLabel.text = self.pokemon.name
                    self.numberLabel.text = String(format: "#%03d",pokemonData.id)
                    
                    for typeEntry in pokemonData.types {
                        if typeEntry.slot == 1 {
                            self.type1Label.text = typeEntry.type.name
                        } else if typeEntry.slot == 2 {
                            self.type2Label.text = typeEntry.type.name
                        }
                    }
                }
            }
            catch let error {
                print("\(error)")
            }
            }).resume()
    }
    
    @IBAction func toggleCatch() {
        pokemonCaught = !pokemonCaught
        UserDefaults.standard.set(pokemonCaught, forKey: pokemon.name)
        setTitle()
    }
    
    func setTitle() {
        if pokemonCaught {
            catchButton.setTitle("Release", for: UIControl.State.normal)
        } else {
            catchButton.setTitle("Catch", for: UIControl.State.normal)
        }
    }
}
