//
//  ViewController.swift
//  Pokedex
//
//  Created by Anton Sankov on 5/13/20.
//  Copyright © 2020 Anton Sankov. All rights reserved.
//

import UIKit

class ViewController: UITableViewController, UISearchBarDelegate {
    @IBOutlet var searchBar: UISearchBar!

    var allPokemons: [Pokemon] = []
    var pokemonsToShow: [Pokemon] = []
    
    func capitalize(text: String) -> String {
        return text.prefix(1).uppercased() + text.dropFirst()
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.searchBar.delegate = self

        let url = URL(string: "https://pokeapi.co/api/v2/pokemon?limit=151")
        guard let u = url else {
            return
        }
        URLSession.shared.dataTask(with: u, completionHandler: { (data, response, error) in
            guard let data = data else {
                return
            }
            
            do {
                let pokemonList = try JSONDecoder().decode(PokemonList.self, from: data)
                self.allPokemons = pokemonList.results
                self.pokemonsToShow = self.allPokemons
                DispatchQueue.main.async {
                    self.tableView.reloadData()
                }
            }
            catch let error {
                print("\(error)")
            }
            }).resume()
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return pokemonsToShow.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "PokemonCell", for: indexPath)
        cell.textLabel?.text = capitalize(text: pokemonsToShow[indexPath.row].name)
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "PokemonSegue" {
            if let destination = segue.destination as? PokemonViewController {
                destination.pokemon = pokemonsToShow[tableView.indexPathForSelectedRow!.row]
            }
        }
    }
    
    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String) {
        if searchText == "" {
            pokemonsToShow = allPokemons
        } else {
            pokemonsToShow = allPokemons.filter({(pokemon) -> Bool in
                return pokemon.name.lowercased().contains(searchText.lowercased())
            })
        }
        
        self.tableView.reloadData()
    }


}

