#!/usr/bin/node

const request = require('request');
const async = require('async');

if (process.argv.length !== 3) {
  console.log('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

const movieId = process.argv[2];
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
  if (error) {
    console.error('Error:', error);
    return;
  }

  if (response.statusCode !== 200) {
    console.log(`Error: ${response.statusCode}`);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  async.eachSeries(characters, (characterUrl, callback) => {
    request(characterUrl, (error, response, body) => {
      if (error) {
        console.error('Error:', error);
        return callback(error);
      }

      if (response.statusCode !== 200) {
        console.log(`Error: ${response.statusCode}`);
        return callback(new Error(`Error: ${response.statusCode}`));
      }

      const characterData = JSON.parse(body);
      console.log(characterData.name);
      callback();
    });
  }, (err) => {
    if (err) {
      console.error('Failed to fetch character names in order:', err);
    }
  });
});
