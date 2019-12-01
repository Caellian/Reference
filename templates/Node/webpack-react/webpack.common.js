const {CheckerPlugin} = require('awesome-typescript-loader')

module.exports = {
  resolve: {extensions: ['.ts', '.tsx', '.js', '.jsx']},

  module: {
    rules: [
      {
        test: /\.scss$/,
        use: [
          {loader: 'style-loader'}, {loader: 'css-loader'},
          {loader: 'resolve-url-loader'}, {
            loader: 'sass-loader',
            options: {sourceMap: true}
          }
        ]
      },
      {
        test: /\.tsx?$/,
        exclude: /node_modules/,
        use: [{loader: 'awesome-typescript-loader'}]
      },
      {enforce: 'pre', test: /\.js$/, loader: 'source-map-loader'}
    ]
  },
  externals: {'react': 'React', 'react-dom': 'ReactDOM'},
  plugins: [new CheckerPlugin()],
};