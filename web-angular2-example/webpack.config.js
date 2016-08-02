var webpack = require("webpack");
var path = require('path');

var ProvidePlugin = require('webpack/lib/ProvidePlugin');
var CommonsChunkPlugin = require('webpack/lib/optimize/CommonsChunkPlugin');
var UglifyJsPlugin = require('webpack/lib/optimize/UglifyJsPlugin');

/*
 * Configuration
 */
module.exports = {
    devtool: 'source-map',
    debug: true,

    entry: {
        'main': './app/main.ts'
    },

    // Bundle configuration
    output: {
        path: root('dist'),
        filename: '[name].bundle.js',
        sourceMapFilename: '[name].map',
        chunkFilename: '[id].chunk.js'
    },

    // Include configuration
    resolve: {
        extensions: ['', '.ts', '.js', '.css', '.html']
    },

    // Module configuration
    module: {
        preLoaders: [
            // Lint all TypeScript files
            {test: /\.ts$/, loader: 'tslint-loader'}
        ],
        loaders: [
            // Include all TypeScript files
            {test: /\.ts$/, loader: 'ts-loader'},

            // Include all HTML files
            {test: /\.html$/, loader: 'raw-loader'},

            // Include all CSS files
            {test: /\.css$/, loader: 'raw-loader'},
        ]
    },

    // Plugin configuration
    plugins: [
        // Bundle all third party libraries
        new CommonsChunkPlugin({name: 'vendor', filename: 'vendor.bundle.js', minChunks: Infinity}),

        // Uglify all bundles
        new UglifyJsPlugin({compress: {warnings: false}}),
    ],

    // Linter configuration
    tslint: {
        emitErrors: false,
        failOnHint: false
    }
};

// Helper functions
function root(args) {
    args = Array.prototype.slice.call(arguments, 0);
    return path.join.apply(path, [__dirname].concat(args));
}
