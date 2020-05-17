//
//  Pokemon.swift
//  Pokedex
//
//  Created by Anton Sankov on 5/13/20.
//  Copyright © 2020 Anton Sankov. All rights reserved.
//

import Foundation

struct PokemonList: Codable {
    let results: [Pokemon]
}

struct PokemonData: Codable {
    let id: Int
    let sprites: PokemonSprites
    let types: [PokemonTypeEntry]
}

struct PokemonTypeEntry: Codable {
    let slot: Int
    let type: PokemonType
}

struct PokemonSprites: Codable {
    let front_default: String
}

struct PokemonType: Codable {
    let name: String
    let url: String
}


struct Pokemon: Codable {
    let name: String
    let url: String
}
